%{

/* 
	Alunos: Mateus Luiz Salvi e Matheus Saueressig
*/
	#include "parser.tab.h"
	#include "tokens.h"
	int lineNumber = 1;
%}


%x COMMENT


%%


"int" { return TK_PR_INT; } //ok
"float" { return TK_PR_FLOAT; } //ok
"bool" { return TK_PR_BOOL; } //ok
"char" { return TK_PR_CHAR; } //ok
"if" { return TK_PR_IF; } //ok
"then" { return TK_PR_THEN; } //ok
"else" { return TK_PR_ELSE; } //ok
"while" { return TK_PR_WHILE; } //ok
"input" { return TK_PR_INPUT; } //ok
"output" { return TK_PR_OUTPUT; } //ok
"return" { return TK_PR_RETURN; } //ok
"for" { return TK_PR_FOR; } //ok


"<=" { return TK_OC_LE; } //ok
">=" { return TK_OC_GE; } //ok
"==" { return TK_OC_EQ; } //ok
"!=" { return TK_OC_NE; } //ok
"&&" { return TK_OC_AND; } //ok
"||" { return TK_OC_OR; } //ok

[-+]?[0-9]+ { return TK_LIT_INT; } 
[+-]?(([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+".")|([0-9]+"."+[0-9]+([eE][+-]?[0-9]+)?)) { return TK_LIT_FLOAT; } 

"false" { return TK_LIT_FALSE; } //ok
"true" { return TK_LIT_TRUE; } //ok
'.' { return TK_LIT_CHAR; }

[A-Za-z]+[A-Za-z]* { return TK_IDENTIFICADOR; } 

[-,;:(){}+*/%^><!=\[\]]  { return yytext[0]; }

[ \t\s]+ { }

\n { lineNumber++; }

"//".* { }


"/*"          { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT>\n   { lineNumber++; }
<COMMENT>.    { }


. { return TK_ERRO; }

%%

int get_line_number()
{
	return lineNumber;
}