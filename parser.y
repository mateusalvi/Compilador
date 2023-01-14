%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror (char *s);
extern int get_line_number();
%}

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

%start Program

%%

Program : VarDecList FuncList
	;

VarDecList : VarDec VarDecList 
	| %empty
	;

VarDec : Type VarList ';'

Type : TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR
	;
	
VarList : ID Array
	| ID ',' VarList
	
Array : '[' LitList ']'

LitList : Lit '^' LitList | Lit
	;

Lit: TK_LIT_INT
	| TK_LIT_FLOAT
	| TK_LIT_FALSE
	| TK_LIT_TRUE
	| TK_LIT_CHAR
	;

FuncList : Func FuncList 
	| %empty

Func : RetType ID '(' ParamList ')' Block

RetType : TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR

ParamList : Param 
	| Param ',' ParamList
	| %empty

Param : Type ID

Block : '{' CommandList '}'
	;

CommandList : Command ';' CommandListEnd
	;
	
CommandListEnd : ';' Command CommandListEnd
	| %empty
	;

Command : VarDec
	| Atrib
	| Flow
	| Ret
	| Block
	| FuncCall
	;

Atrib : ID Array TK_OC_EQ Expr

Flow : TK_PR_IF '(' Expr ')' TK_PR_THEN Command Else
	| TK_PR_WHILE '(' Expr ')' Block
	;

Else: TK_PR_ELSE Command
	| %empty
	;

Ret : "return" Expr

FuncCall : ID '(' ExprList ')'

ID: TK_IDENTIFICADOR

ExprList : Expr ',' ExprList
	| Expr
	| %empty

Expr : E
	| ID
	| Func
	| LitList
	;

E : E TK_OC_OR T | T
T : T TK_OC_AND F | F
F : F TK_OC_EQ G | F TK_OC_NE G | G
G : G TK_OC_LE I | G TK_OC_GE I | I
I : I '+' J | I '-' J | J
J : J '*' K | J '/' K | J '%' K | K
K : '-' L | '!' L
L : '(' E ')' | E

%%

int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	exit(3);
}

int main() {
    if (yyparse() == 0) {
        printf("The input is grammatically correct\n");
    }
    return 0;
}