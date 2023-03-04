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

%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR

%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_IDENTIFICADOR

%token TK_ERRO

%type<valor_lexico> TK_PR_INT
%type<valor_lexico> TK_PR_FLOAT
%type<valor_lexico> TK_PR_BOOL
%type<valor_lexico> TK_PR_CHAR
%type<valor_lexico> TK_PR_IF
%type<valor_lexico> TK_PR_THEN
%type<valor_lexico> TK_PR_ELSE
%type<valor_lexico> TK_PR_WHILE
%type<valor_lexico> TK_PR_INPUT
%type<valor_lexico> TK_PR_OUTPUT
%type<valor_lexico> TK_PR_RETURN
%type<valor_lexico> TK_PR_FOR

%type<valor_lexico> TK_OC_LE
%type<valor_lexico> TK_OC_GE
%type<valor_lexico> TK_OC_EQ
%type<valor_lexico> TK_OC_NE
%type<valor_lexico> TK_OC_AND
%type<valor_lexico> TK_OC_OR

%type<valor_lexico> TK_LIT_INT
%type<valor_lexico> TK_LIT_FLOAT
%type<valor_lexico> TK_LIT_FALSE
%type<valor_lexico> TK_LIT_TRUE
%type<valor_lexico> TK_LIT_CHAR
%type<valor_lexico> TK_IDENTIFICADOR

%type<tree> ID
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
%type<tree> Param
%type<tree> Command
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

%start Program

%%

Program : DecList { arvore = (void*)$$; $$ = $1; }
	;

DecList : Dec DecList {  $$ = $1; asd_add_child($$,$2); }
	| Dec { $$ = $1; }
	;

Dec : Type VarList ';' { $$ = $2; }
    | Type Func { $$ = $2; }
    ;

DecLocal: Type VarListLocal { $$ = $2; }

VarListLocal : ID ',' VarListLocal { $$ = $1; asd_add_child($$,$3); }
        | ID TK_OC_LE Lit ',' VarListLocal { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $5); }
		| ID TK_OC_LE Lit { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); }
		| ID { $$ = $1; }
		;

Type : TK_PR_INT { $$ = asd_new(create_leaf($1)); asd_free_node($$); }
	| TK_PR_FLOAT { $$ = asd_new(create_leaf($1)); asd_free_node($$); }
	| TK_PR_BOOL { $$ = asd_new(create_leaf($1)); asd_free_node($$); }
	| TK_PR_CHAR { $$ = asd_new(create_leaf($1)); asd_free_node($$); }
	;

VarList : ID ',' VarList { $$ = $1; asd_add_child($$,$3); }
		| ID { $$ = $1; }
		| ID '[' ArrayDim ']' ',' VarList { $$ = asd_new("[]"), asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $6); }
		| ID '[' ArrayDim ']' { $$ = asd_new("[]"), asd_add_child($$, $1); asd_add_child($$, $3); }
		;

ArrayDim : Expr '^' ArrayDimEnd  { $$ = asd_new("^"); asd_add_child($$,$1); asd_add_child($$,$3); }
	| Expr { $$ = $1; }
    ;

ArrayDimEnd : Expr '^' ArrayDimEnd { $$ = asd_new("^"); asd_add_child($$,$1); asd_add_child($$,$3); }
    | Expr { $$ = $1; }
    ;

Lit : TK_LIT_INT { $$ = asd_new(create_leaf($1)); }
    | TK_LIT_FLOAT { $$ = asd_new(create_leaf($1)); }
    | TK_LIT_FALSE { $$ = asd_new(create_leaf($1)); }
    | TK_LIT_TRUE { $$ = asd_new(create_leaf($1)); }
    | TK_LIT_CHAR { $$ = asd_new(create_leaf($1)); }
    ;

Func : ID '(' ')' Block { $$ = $1; if($4){ asd_add_child($$,$4); }; }
	| ID '(' ParamList ')' Block { $$ = $1; asd_add_child($$,$3); if($5){ asd_add_child($$,$5); }; }
	;

ParamList : Param ',' ParamList { $$ = $1; asd_add_child($$,$3); }
	| Param { $$ = $1; }
	;

Param : Type ID { $$ = $2; }
	;

Block : '{' CommandList '}'  { $$ = $2; }
	| '{' '}' { $$ = NULL; }
	;

CommandList : Command ';' CommandList { if($1){ $$ = $1; }; if($3){ asd_add_child($$,$3); }; }
	| Command ';' { if($1){ $$ = $1; }; }

Command : Flow { $$ = $1; }
	| DecLocal { $$ = $1; }
	| Atrib { ; $$ = $1; }
	| Ret { $$ = $1; }
	| FuncCall { $$ = $1; }
	| Block { $$ = $1; }
	;

Atrib : ID '=' Expr { $$ = asd_new("="); asd_add_child($$,$1); asd_add_child($$,$3); }
	| ID '[' ArrayDim ']' '=' Expr { $$ = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child($$, col); asd_add_child($$, $6); asd_add_child(col, $1); asd_add_child(col,$3); }
	| ID '=' ID '[' ArrayDim ']' { $$ = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child($$, col); asd_add_child(col, $3); asd_add_child($$, $5); }
	;

Flow : TK_PR_WHILE '(' Expr ')' Block { $$ = asd_new("while"); asd_add_child($$, $3); if($5){ asd_add_child($$, $5); }; }
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block  { $$ = asd_new("if"); asd_add_child($$, $3); if($6){ asd_add_child($$, $6); }; }
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block TK_PR_ELSE Block { $$ = asd_new("if"); asd_add_child($$, $3); if($6){ asd_add_child($$, $6); }; if($8){ asd_add_child($$, $8); }; }
	;

Ret : TK_PR_RETURN Expr { $$ = $2; }
	;

FuncCall : ID '(' ExprList ')' { $$ = $1; asd_add_child($$, $3); }
	| ID '(' ')' { $$ = $1; }
	;

ID: TK_IDENTIFICADOR { $$ = asd_new(create_leaf($1)); }
	;

Expr : Expr TK_OC_OR T  { $$ = asd_new("||"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| T { $$ = $1; }
T : T TK_OC_AND F { $$ = asd_new("&&"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| F { $$ = $1; }
F : F TK_OC_EQ G { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| F TK_OC_NE G { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| G { $$ = $1; }
G : G TK_OC_LE I { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| G TK_OC_GE I { $$ = asd_new(">="); asd_add_child($$, $1); asd_add_child($$, $3); }
	| G '>' I { $$ = asd_new(">"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| G '<' I { $$ = asd_new("<"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| I { $$ = $1; }
I : I '+' J { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| I '-' J { $$ = asd_new("-"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| J { $$ = $1; }
J : J '*' K { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| J '/' K { $$ = asd_new("/"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| J '%' K { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); }
	| K { $$ = $1; }
K : '-' L { $$ = asd_new("-"); asd_add_child($$, $2); }
	| '!' L { $$ = asd_new("!"); asd_add_child($$, $2); }
	| L { $$ = $1; }
L : '(' Expr ')' { $$ = $2; }
	| FuncCall  { $$ = $1; }
	| ID '[' ArrayDim ']'
	| ID { $$ = $1; } 
	| Lit { $$ = $1; }

ExprList : Expr ',' ExprList {$$ = $1; asd_add_child($$,$3);}
	| Expr { $$ = $1; }
	;

%%

int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	return 0;
}