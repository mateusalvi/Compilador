%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asd.h>
int yylex();
int yyerror (char *s);
extern int yydebug;
yydebug = 1;
extern int get_line_number();
extern void *asd_tree_t;
extern struct node_t;

%}

%union
{
	node_t valor_lexico;
	asd_tree_t *tree;
}

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_FOR

%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR

%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_LIT_CHAR

%token<valor_lexico> TK_IDENTIFICADOR
%token TK_ERRO

%type<asd_tree> Program
%type<asd_tree> DecList
%type<asd_tree> Dec
%type<asd_tree> Block
%type<asd_tree> DecLocal
%type<asd_tree> VarListLocal
%type<asd_tree> Type
%type<asd_tree> VarList
%type<asd_tree> ArrayDimEnd
%type<asd_tree> ArrayDim
%type<asd_tree> Lit
%type<asd_tree> Func
%type<asd_tree> ParamList
%type<asd_tree> ParamListEnd
%type<asd_tree> Param
%type<asd_tree> Command
%type<asd_tree> CommandListEnd
%type<asd_tree> CommandList
%type<asd_tree> Atrib
%type<asd_tree> Flow
%type<asd_tree> Ret
%type<asd_tree> FuncCall
%type<asd_tree> ID
%type<asd_tree> Expr
%type<asd_tree> T
%type<asd_tree> F
%type<asd_tree> G
%type<asd_tree> I
%type<asd_tree> J
%type<asd_tree> K
%type<asd_tree> L
%type<asd_tree> ExprList
%type<asd_tree> ExprListEnd

%start Program

%%

Program : DecList { arvore = (void*)$$; $$ = $1; }
	;

DecList :
	| Dec DecList { $$ = $1; add_child($$,$2); create_node(); }
	;

Dec : Type VarList ';' { $$ = $1; add_child($$,$2); }
	| Type Func { $$ = $1; add_child($$,$2); }
	;

DecLocal: Type VarListLocal { $$ = $1; add_child($$,$2); }

VarListLocal :
        | ID ',' VarListLocal {$$ = $1; add_child($$,$3); }
        | ID TK_OC_LE Lit ',' VarListLocal
		| ID { $$ = $1; }
        | ID TK_OC_LE Lit { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); }
		;

Type : TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR
	;

VarList : ID ',' VarList {$$ = $1; add_child($$,$3);}
        | ID '[' ArrayDim ']' ',' VarList
		| ID { $$ = $1; }
        | ID '[' ArrayDim ']' { $$ = asd_new("[]"); asd_add_child($$, $1); asd_add_child($$, $3); }
		;
/*
ArrayDimDec: TK_LIT_INT '^' ArrayDimDecEnd
			| TK_LIT_INT;
ArrayDimDecEnd: TK_LIT_INT '^' ArrayDimDecEnd
			| TK_LIT_INT;
*/
ArrayDim : Expr '^' ArrayDimEnd  { $$ = $1; add_child($$,$3); }
	| Expr { $$ = $1; }
    ;

ArrayDimEnd : Expr '^' ArrayDimEnd { $$ = $1; add_child($$,$3); }
    | Expr { $$ = $1; }
    ;

Lit : TK_LIT_INT  { node_t* new_node; new_node = calloc(1,sizeof(node_t)); char* leaf; leaf = create_leaf($1); new_node = create_node(AST_LIT_INT,leaf) };
    | TK_LIT_FLOAT { node_t* new_node; new_node = calloc(1,sizeof(node_t)); char* leaf; leaf = create_leaf($1); new_node = create_node(AST_LIT_FLOAT,leaf) };
    | TK_LIT_FALSE { node_t* new_node; new_node = calloc(1,sizeof(node_t)); char* leaf; leaf = create_leaf($1); new_node = create_node(AST_LIT_FALSE,leaf) };
    | TK_LIT_TRUE { node_t* new_node; new_node = calloc(1,sizeof(node_t)); char* leaf; leaf = create_leaf($1); new_node = create_node(AST_LIT_TRUE,leaf) };
    | TK_LIT_CHAR { node_t* new_node; new_node = calloc(1,sizeof(node_t)); char* leaf; leaf = create_leaf($1); new_node = create_node(AST_LIT_CHAR,leaf) };
    ;

Func : ID '(' ParamList ')' Block { char label[100] = "call ", *nome_fun; nome_fun = strdup(create_leaf($1)); strcat(label,nome_fun); $$ = create_node(AST_CALL,label); add_child($$,$5); };
	| ID '(' ')' Block { $$ = asd_new("()"); asd_add_child($$, $1); asd_add_child($$, $4); }
	;

ParamList : Param ParamListEnd {$$ = $1; add_child($$,$2);}
	;

ParamListEnd :
	| ',' Param ParamListEnd {$$ = $2; add_child($$,$3);}
	;

Param : Type ID { asd_add_child($$, $1); asd_add_child($$, $2); }
	;

Block : '{' CommandList '}'  { $$ = $2; }
	| '{' '}'
	;

CommandList : Command CommandListEnd {$$ = $1; add_child($$,$2);}
	;

CommandListEnd : ';'
	| ';' Command CommandListEnd {$$ = $2; add_child($$,$3);}
	;

Command : Block { $$ = $1; }
	| Flow { $$ = $1; }
	| Atrib { $$ = $1; }
	| DecLocal { $$ = $1; }
	| Ret { $$ = $1; }
	| FuncCall { $$ = $1; }
	;

Atrib : ID '=' Expr { $$ = asd_new("="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| ID '[' ArrayDim ']' '=' Expr { $$ = asd_new("="); node_t *col = asd_new("[]"); asd_add_child($$, col); asd_add_child($$, $6); asd_add_child(col, $1); asd_add_child(col,$3); }
	;

Flow : TK_PR_WHILE '(' Expr ')' Block { $$ = asd_new("while"); asd_add_child($$, $3); asd_add_child($$, $5); }
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block  { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $6); }
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block TK_PR_ELSE Block { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $6); asd_add_child($$, $8); }
	;

Ret : TK_PR_RETURN Expr {$$ = $2;}
	;

FuncCall : ID '(' ExprList ')' { $$ = asd_new("( )"); asd_add_child($$, $1); asd_add_child($$, $3); }
		| ID '(' ')' { $$ = $1; }
	;

ID: TK_IDENTIFICADOR {node_t* new_node; new_node = calloc(1,sizeof(node_t)); char* leaf; leaf = create_leaf($1); new_node = create_node(AST_LIT_INT,leaf)};
	;

Expr : Expr TK_OC_OR T  { $$ = asd_new("&&"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| T { $$ = $1; }
T : T TK_OC_AND F { $$ = asd_new("||"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| F { $$ = $1; }
F : F TK_OC_EQ G { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| F TK_OC_NE G { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| G { $$ = $1; }
G : G TK_OC_LE I { $$ = asd_new(">="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| G TK_OC_GE I { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| I { $$ = $1; }
I : I '+' J { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| I '-' J { $$ = asd_new("-"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| J { $$ = $1; }
J : J '*' K { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| J '/' K { $$ = asd_new("/"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| J '%' K { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| K { $$ = $1; }
K : '-' L { $$ = $2; }
	| '!' L { $$ = $2; }
	| L { $$ = $1; }
L : '(' Expr ')' { $$ = $2; }
	| FuncCall  { $$ = $1; }
	| ID '[' ArrayDim ']'
	| ID { $$ = $1; }
	| Lit { $$ = $1; }

ExprList : Expr ExprListEnd {$$ = $1; add_child($$,$2);}
	;

ExprListEnd :
	| ',' Expr ExprListEnd {$$ = $2; add_child($$,$2);}
	;

%%

int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	return 0;
}
