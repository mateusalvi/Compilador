%{
	#include "parser.tab.h"
	#include "asd.h"
	#include "hash.h"
	#include "stack.h"

	enum types{
		IDENTIFICADOR = 0,
		INT = 1,
		FLOAT = 2,
		BOOL = 3,
		CHAR = 4,
		PR_INT = 5,
		PR_FLOAT = 6,
		PR_BOOL = 7,
		PR_CHAR = 8,
		PR_IF = 9,
		PR_THEN = 10,
		PR_ELSE = 11,
		PR_WHILE = 12,
		PR_INPUT = 13,
		PR_OUTPUT = 14,
		PR_RETURN = 15,
		PR_FOR = 16,
		OC_LE = 17,
		OC_GE = 18,
		OC_EQ = 19,
		OC_NE = 20,
		OC_AND = 21,
		OC_OR = 22,
		SPECIAL_CHARACTER = 23
	};
	
	int lineNumber = 1;
%}

%x COMMENT

%%

"int" { yylval.valor_lexico.atLine = get_line_number(); 
		yylval.valor_lexico.type = PR_INT; 
		yylval.valor_lexico.value.valueChar = strdup(yytext); 
		return TK_PR_INT; }

"float" { yylval.valor_lexico.atLine = get_line_number(); 
		  yylval.valor_lexico.type = PR_FLOAT; 
		  yylval.valor_lexico.value.valueChar = strdup(yytext); 
		  return TK_PR_FLOAT; }

"bool" { yylval.valor_lexico.atLine = get_line_number(); 
		yylval.valor_lexico.type = PR_BOOL; 
		yylval.valor_lexico.value.valueChar = strdup(yytext); 
		return TK_PR_BOOL; }

"char" { yylval.valor_lexico.atLine = get_line_number(); 
		 yylval.valor_lexico.type = PR_CHAR; 
		 yylval.valor_lexico.value.valueChar = strdup(yytext); 
		 return TK_PR_CHAR; }

"if" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = PR_IF; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext); 
	   return TK_PR_IF; }

"then" { yylval.valor_lexico.atLine = get_line_number(); 
		 yylval.valor_lexico.type = PR_THEN; 
		 yylval.valor_lexico.value.valueChar = strdup(yytext); 
		 return TK_PR_THEN; }

"else" { yylval.valor_lexico.atLine = get_line_number(); 
		 yylval.valor_lexico.type = PR_ELSE; 
		 yylval.valor_lexico.value.valueChar = strdup(yytext); 
		 return TK_PR_ELSE; }

"while" { yylval.valor_lexico.atLine = get_line_number(); 
		  yylval.valor_lexico.type = PR_WHILE; 
		  yylval.valor_lexico.value.valueChar = strdup(yytext); 
		  return TK_PR_WHILE; }

"input" { yylval.valor_lexico.atLine = get_line_number(); 
		  yylval.valor_lexico.type = PR_INPUT; 
		  yylval.valor_lexico.value.valueChar = strdup(yytext); 
		  return TK_PR_INPUT; }

"output" { yylval.valor_lexico.atLine = get_line_number(); 
		   yylval.valor_lexico.type = PR_OUTPUT; 
		   yylval.valor_lexico.value.valueChar = strdup(yytext); 
		   return TK_PR_OUTPUT; }

"return" { yylval.valor_lexico.atLine = get_line_number(); 
		   yylval.valor_lexico.type = PR_RETURN; 
		   yylval.valor_lexico.value.valueChar = strdup(yytext); 
		   return TK_PR_RETURN; }

"for" { yylval.valor_lexico.atLine = get_line_number(); 
		yylval.valor_lexico.type = PR_FOR; 
		yylval.valor_lexico.value.valueChar = strdup(yytext); 
		return TK_PR_FOR; }

"<=" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = OC_LE; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext); 
	   return TK_OC_LE; }

">=" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = OC_GE; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext); 
	   return TK_OC_GE; }

"==" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = OC_EQ; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext); 
	   return TK_OC_EQ; }

"!=" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = OC_NE; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext); 
	   return TK_OC_NE; }

"&&" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = OC_AND; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext);
	   return TK_OC_AND; }

"||" { yylval.valor_lexico.atLine = get_line_number(); 
	   yylval.valor_lexico.type = OC_OR; 
	   yylval.valor_lexico.value.valueChar = strdup(yytext);
	   return TK_OC_OR; }

[-+]?[0-9]+			{ yylval.valor_lexico.atLine = get_line_number(); 
					  yylval.valor_lexico.type =  INT; 
					  yylval.valor_lexico.value.valueInt = atoi(yytext); 
					  yylval.valor_lexico.value.valueChar = strdup(yytext); 
					  return TK_LIT_INT; } 

[+-]?(([0-9]+"."[0-9]+)|("."[0-9]+)|([0-9]+".")|([0-9]+"."+[0-9]+([eE][+-]?[0-9]+)?)) { yylval.valor_lexico.atLine = get_line_number(); 
					yylval.valor_lexico.type = FLOAT; 
					yylval.valor_lexico.value.valueFloat = atof(yytext); 
					yylval.valor_lexico.value.valueChar = strdup(yytext);  
					return TK_LIT_FLOAT; } 

"false"				{ yylval.valor_lexico.atLine = get_line_number(); 
					  yylval.valor_lexico.type = BOOL; 
					  yylval.valor_lexico.value.valueInt = 0; 
					  yylval.valor_lexico.value.valueChar = strdup(yytext);  
					  return TK_LIT_FALSE; }

"true"				{ yylval.valor_lexico.atLine = get_line_number(); 
					  yylval.valor_lexico.type = BOOL; 
					  yylval.valor_lexico.value.valueInt = 1; 
					  yylval.valor_lexico.value.valueChar = strdup(yytext); 
					  return TK_LIT_TRUE; }

'.'					{ yylval.valor_lexico.atLine = get_line_number(); 
					  yylval.valor_lexico.type = CHAR; 
					  yylval.valor_lexico.value.valueChar = strdup(yytext); 
					  return TK_LIT_CHAR; }

[A-Za-z]+[A-Za-z]*  { yylval.valor_lexico.atLine = get_line_number(); 
					  yylval.valor_lexico.type = IDENTIFICADOR; 
					  yylval.valor_lexico.value.valueChar = strdup(yytext); 
					  return TK_IDENTIFICADOR; } 

[-,;:(){}+*/%\^><!=\[\]]  { yylval.valor_lexico.atLine = get_line_number(); 
							yylval.valor_lexico.type = SPECIAL_CHARACTER; 
							yylval.valor_lexico.value.valueChar = strdup(yytext); 
							return yytext[0]; }

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