%{
int yylex(void);
void yyerror (char const *s);
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

%%

programa:

Program : VarDecList FuncList
VarDecList : VarDec VarDecList | e
VarDec : Type VarList ';'
Type : "int" | "float" | "bool" | "char"
VarList : ID Array | ID ',' VarList
Array : '[' LitList ']'
LitList : Lit ',' LitList | Lit
FuncList : Func FuncList | e
Func : RetType ID '(' ParamList ')' Block
RetType : "int" | "float" | "bool" | "char"
ParamList : Param | Param ',' ParamList | e
Param : Type ID
Block : '{' CommandList '}'
CommandList : Command ';' CommandList | e
Command : VarDec | Atrib | Flow | Ret | Block | FuncCall
Atrib : ID Array '=' Expr
Flow : "if" '(' Expr ')' Command ["else" Command]
Ret : "return" Expr
FuncCall : ID '(' ExprList ')'
ExprList : Expr ',' ExprList | Expr | e

Expr : E 

E : E 'or' T | T
T : T 'and' F | F
F : F '==' G | F '=!' G | G
G : G '<' I | G '>' I | G '<=' I | G '>=' I | I
I : I '+' J | I '-' J | J
J : J '*' K | J '/' K | J '%' K | K
K : '-' L | '!' L
L : '( 'E ')' | E

%%

int yyerror(char *err){
	
	fprintf(stderr, "ERROR in line = %d\n", getLineNumber());
	exit(3);
}