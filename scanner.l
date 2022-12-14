%{
	#include "tokens.h"
	int lineNumber = 1;
%}


%x C_COMMENT


%%
"int" { return TK_PR_INT; }
"float" { return TK_PR_FLOAT; }
"bool" { return TK_PR_BOOL; }
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

[0-9]+ { return TK_LIT_INT; }
(([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+".")) { return TK_LIT_FLOAT; }
"false" { return TK_LIT_FALSE; }
"true" { return TK_LIT_TRUE; }
'.' { return TK_LIT_CHAR; }
[A-Za-z_][A-Za-z_0-9]* { return TK_IDENTIFICADOR; }
. { return TK_ERRO; }


[ \n]+ { lineNumber++; }
[ \t\r]+ { }
"//" { }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]  { }

<C_COMMENT>"/*" { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }


<C_COMMENT>[!-~_] return yytext[0];
<C_COMMENT>"\n"   { return lineNumber++; }
<C_COMMENT>.    { }
%%

int get_line_number()
{
	return lineNumber;
}
