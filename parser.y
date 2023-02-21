%code requires {
	
#define YYDEBUG 1

#define ASD_LIT_FALSE 0
#define ASD_LIT_TRUE 1
#define ASD_LIT_INT 2
#define ASD_LIT_FLOAT 3
#define ASD_LIT_CHAR 4
#define ASD_CALL 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asd.h"
int yylex();
int yyerror (char *s);
extern int yydebug;
extern int get_line_number();
extern void *arvore;
}

%union
{
	value_t valor_lexico;
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

%type<tree> TK_PR_INT
%type<tree> TK_PR_FLOAT
%type<tree> TK_PR_BOOL
%type<tree> TK_PR_CHAR

%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR

%token TK_ERRO

%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_IDENTIFICADOR

%type<valor_lexico> TK_LIT_INT
%type<valor_lexico> TK_LIT_FLOAT
%type<valor_lexico> TK_LIT_FALSE
%type<valor_lexico> TK_LIT_TRUE
%type<valor_lexico> TK_LIT_CHAR
%type<valor_lexico> TK_IDENTIFICADOR
%type<valor_lexico> ID

%type<tree> Program
%type<tree> DecList
%type<tree> Dec
%type<tree> Block
%type<tree> DecLocal
%type<tree> VarListLocal
%type<tree> Type
%type<tree> VarList
%type<tree> ArrayDimEnd
%type<tree> ArrayDim
%type<tree> Lit
%type<tree> Func
%type<tree> ParamList
%type<tree> ParamListEnd
%type<tree> Param
%type<tree> Command
%type<tree> CommandListEnd
%type<tree> CommandList
%type<tree> Atrib
%type<tree> Flow
%type<tree> Ret
%type<tree> FuncCall
%type<tree> Expr
%type<tree> T
%type<tree> F
%type<tree> G
%type<tree> I
%type<tree> J
%type<tree> K
%type<tree> L
%type<tree> ExprList
%type<tree> ExprListEnd

%start Program

%%

Program : DecList { printf("ola"); arvore = (void*)$$; $$ = $1; }
	;

DecList :
	| Dec DecList { $$ = $1; asd_add_child($$,$2); }
	;

Dec : Type VarList ';' { $$ = $2; }//asd_add_child($$,$2); }
	| Type Func { $$ = $2; }//asd_add_child($$,$2); }
	;

DecLocal: Type VarListLocal { $$ = $2; }//asd_add_child($$,$2); }

VarListLocal :
        | ID ',' VarListLocal { $$ = $3; asd_add_child($$,$3); }
        | ID TK_OC_LE Lit ',' VarListLocal { $$ = asd_new("<="); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child($$, new_child); asd_add_child($$, $3); asd_add_child($$, $5); }
		| ID { $$ = NULL; }
        | ID TK_OC_LE Lit { $$ = asd_new("<="); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child($$, new_child); asd_add_child($$, $3); }
		;

Type : TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR
	;

VarList : ID ',' VarList {$$ = $3;}
        | ID '[' ArrayDim ']' ',' VarList { $$ = asd_new("[]"); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child($$, new_child); asd_add_child($$, $3); asd_add_child($$, $6); }
		| ID { $$ = NULL; }
        | ID '[' ArrayDim ']' { $$ = asd_new("[]"); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child($$, new_child); asd_add_child($$, $3); }
		;
/*
ArrayDimDec: TK_LIT_INT '^' ArrayDimDecEnd
			| TK_LIT_INT;
ArrayDimDecEnd: TK_LIT_INT '^' ArrayDimDecEnd
			| TK_LIT_INT;
*/
ArrayDim : Expr '^' ArrayDimEnd  { $$ = $1; asd_add_child($$,$3); }
	| Expr { $$ = $1; }
    ;

ArrayDimEnd : Expr '^' ArrayDimEnd { $$ = $1; asd_add_child($$,$3); }
    | Expr { $$ = $1; }
    ;

Lit : TK_LIT_INT  { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); }
    | TK_LIT_FLOAT { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); }
    | TK_LIT_FALSE { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); }
    | TK_LIT_TRUE { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); }
    | TK_LIT_CHAR { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); }
    ;

Func : ID '(' ParamList ')' Block { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child(new_child,$3); asd_add_child(new_child,$5); $$ = new_child;};
	| ID '(' ')' Block { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child(new_child, $4); $$ = new_child; }
	;

ParamList : Param ParamListEnd {$$ = $1; asd_add_child($$,$2);}
	;

ParamListEnd :
	| ',' Param ParamListEnd {$$ = $2; asd_add_child($$,$3);}
	;

Param : Type ID { asd_add_child($$, $1); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($2); new_child = asd_new(leaf); asd_add_child($$, new_child); }
	;

Block : '{' CommandList '}'  { $$ = $2; }
	| '{' '}'
	;

CommandList : Command CommandListEnd { $$ = $1; asd_add_child($$,$2); }
	;

CommandListEnd : ';'
	| ';' Command CommandListEnd { $$ = $2; asd_add_child($$,$3); }
	;

Command : Block { $$ = $1; }
	| Flow { $$ = $1; }
	| Atrib { $$ = $1; }
	| DecLocal { $$ = $1; }
	| Ret { $$ = $1; }
	| FuncCall { $$ = $1; }
	;

Atrib : ID '=' Expr { $$ = asd_new("="); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child($$, new_child); asd_add_child($$, $3); }
	| ID '[' ArrayDim ']' '=' Expr { $$ = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child($$, col); asd_add_child($$, $6); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child(col, new_child); asd_add_child(col,$3); }
	;

Flow : TK_PR_WHILE '(' Expr ')' Block { $$ = asd_new("while"); asd_add_child($$, $3); asd_add_child($$, $5); }
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block  { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $6); }
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block TK_PR_ELSE Block { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $6); asd_add_child($$, $8); }
	;

Ret : TK_PR_RETURN Expr { $$ = $2; }
	;

FuncCall : ID '(' ExprList ')' { $$ = asd_new("( )"); asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); asd_add_child($$, new_child); asd_add_child($$, $3); }
		| ID '(' ')' { char label[100] = "call ", *fn_name; fn_name = strdup(create_leaf($1)); strcat(label,fn_name); $$ = asd_new(label); }
	;

ID: TK_IDENTIFICADOR  { $$ = $1; }//{value_t* new_child; new_child = calloc(1,sizeof(value_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); $$ = new_child; }
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
	| ID { asd_tree_t* new_child; new_child = calloc(1,sizeof(asd_tree_t)); char* leaf; leaf = create_leaf($1); new_child = asd_new(leaf); $$ = new_child; }
	| Lit { $$ = $1; }

ExprList : Expr ExprListEnd {$$ = $1; asd_add_child($$,$2);}
	;

ExprListEnd :
	| ',' Expr ExprListEnd {$$ = $2; asd_add_child($$,$2);}
	;

%%

int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	return 0;
}
