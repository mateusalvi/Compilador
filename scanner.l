%{
	#define IDENTIFICADOR 0 
	#define INT 1
	#define FLOAT 2
	#define BOOL 3
	#define CHAR 4

	#include "parser.tab.h"
	#include "asd.h"
	#include "y.tab.h"

	int lineNumber = 1;
%}

%x COMMENT

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
">=" { return TK_OC_GE; } 
"==" { return TK_OC_EQ; } 
"!=" { return TK_OC_NE; } 
"&&" { return TK_OC_AND; } 
"||" { return TK_OC_OR; } 

[-+]?[0-9]+			{ yylval.valor_lexico.atLine, yyval.valor_lexico.type, yyval.valor_lexico.intVal = get_line_number(), INT, atoi(yytext) ; return TK_LIT_INT; } 
[+-]?(([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+".")|([0-9]+"."+[0-9]+([eE][+-]?[0-9]+)?)) { yyval.valor_lexico.atLine, yyval.valor_lexico.type, yyval.valor_lexico.floatVal = get_line_number(), FLOAT, atof(yytext) ; return TK_LIT_FLOAT; } 

"false"				{ yyval.valor_lexico.atLine, yyval.valor_lexico.type, yyval.valor_lexico.boolVal = get_line_number(), BOOL, 0 ; return TK_LIT_FALSE; }
"true"				{ yyval.valor_lexico.atLine, yyval.valor_lexico.type, yyval.valor_lexico.boolVal = get_line_number(), BOOL, 1 ; return TK_LIT_TRUE; }

'.'					{ yyval.valor_lexico.atLine, yyval.valor_lexico.type, yyval.valor_lexico.charVal = get_line_number(), CHAR, strdup(strcpy(yytext)) ; return TK_LIT_CHAR; }

[A-Za-z]+[A-Za-z]*  { yylval.valor_lexico.atLine, yyval.valor_lexico.type, yyval.valor_lexico.charVal = get_line_number(), IDENTIFICADOR, strdup(strcpy(yytext)) ; return TK_IDENTIFICADOR; } 

[-,;:(){}+*/%\^><!=\[\]]  { return yytext[0]; }

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