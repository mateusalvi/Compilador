%{
	#include "tokens.h"
}%

%%

"int" { return TK_PR_INT; }
"float" { return TK_PR_FLOAT; }
"bool" { return TK_PR_BOOL}
"char" { return TK_PR_CHAR; }
"if" { return TK_PR_IF; }
"then" { return TK_PR_THEN; }
"else" { return TK_PR_ELSE; }
"while" { return TK_PR_WHILE; }
"input" { return TK_PR_INPUT; }
"output" { return TK_PR_OUTPUT; }
"return" { return TK_PR_RETURN; }
"for" { return TK_PR_FOR; }
"<=" { return TK_OC_LE; }
">+" { return TK_OC_GE; }
"==" { return TK_OC_EQ; }
"!=" { return TK_OC_NE; }
"&&" { return TK_OC_AND; }
"||" { return TK_OC_OR; }
 { return TK_LIT_INT; }
 { return TK_LIT_FLOAT; }
 { return TK_LIT_FALSE; }
 { return TK_LIT_TRUE; }
 { return TK_LIT_CHAR; }
 { return TK_IDENTIFICADOR; }
 { return TK_ERRO; }

%%

int Get_LineNumber()
{
	return l;
}