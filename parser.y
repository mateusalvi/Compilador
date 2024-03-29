%code requires {
	
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asd.h"
#include "iloc.h"
#include "stack.h"


int yylex();
int yyerror (char *s);
extern int yydebug;
extern int get_line_number();
extern void *arvore;
extern value_t * hash_table[TABLE_SIZE];
extern iloc_operations_list *iloc_list;
extern iloc_operation *op;
extern value_t *value;
extern Pilha* stack; 

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
%type<tree> Type
%type<tree> VarList
%type<tree> ArrayDim
%type<tree> Lit
%type<tree> Func
%type<tree> ParamList
%type<tree> Param
%type<tree> Command
%type<tree> CommandList
%type<tree> VarListLocal
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

Program : PushTable DecList { if($2){arvore = (void*)$$; $$ = $2; }}
	;

DecList : Dec DecList { $$ = $1; if($2){asd_add_child($$,$2);} }
	| Dec { if($1){$$ = $1;} else{$$ = NULL;} }
	;

Dec : Type VarList ';' { if($2){ $$ = $2; } else{$$ = NULL; }  } 
    | Type Func { $$ = $2; }
    ;

VarList : ID',' VarList {  $$ = $1; asd_add_child($$,$3);  if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); print_table();}} // replicar em todas as inserções na tabela
		| ID{ $$ = $1;  if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); print_table();}   }
		| ID'[' ArrayDim ']' ',' VarList { $$ = asd_new("[]"), asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $6);   if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);}  }
		| ID'[' ArrayDim ']' { $$ = asd_new("[]"), asd_add_child($$, $1); asd_add_child($$, $3);  if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);}  }
		;



Type : TK_PR_INT { $$ = NULL; }
	| TK_PR_FLOAT { $$ = NULL; } //$$ = asd_new(create_leaf($1)); asd_free_node($$); }
	| TK_PR_BOOL { $$ = NULL; } //$$ = asd_new(create_leaf($1)); asd_free_node($$); }
	| TK_PR_CHAR { $$ = NULL; } //$$ = asd_new(create_leaf($1)); asd_free_node($$); }
	;



ArrayDim : Expr '^' ArrayDim  { $$ = asd_new("^"); asd_add_child($$,$1); asd_add_child($$,$3); }
	| Expr { $$ = $1; }
    ;

Lit : TK_LIT_INT { $$ = asd_new(create_leaf($1)); $$->value = $1; print_table(); $$->temp = new_temp(); op = new_iloc_operation("loadI", "r1",NULL, $$->temp); append_iloc_operation(iloc_list,op); }
    | TK_LIT_FLOAT { $$ = asd_new(create_leaf($1)); $$->value = $1; print_table(); $$->temp = new_temp(); hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1)); push(stack,hp);}
    | TK_LIT_FALSE { $$ = asd_new(create_leaf($1)); $$->value = $1; print_table(); $$->temp = new_temp(); hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1)); push(stack,hp);}
    | TK_LIT_TRUE { $$ = asd_new(create_leaf($1)); $$->value = $1; print_table(); $$->temp = new_temp(); hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1)); push(stack,hp);}
    | TK_LIT_CHAR { $$ = asd_new(create_leaf($1)); $$->value = $1; print_table(); $$->temp = new_temp(); hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1)); push(stack,hp);}
    ;

Func : ID PushTable '(' ')' Block PopTable { $$ = $1; if($5){ asd_add_child($$,$5); }; if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; exit(4);} else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);
       $1->value.value_rot = strdup(new_rot()); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("nop", NULL,NULL, $1->value.value_rot) ; append_iloc_operation(iloc_list,op); $$->code = iloc_list; print_table();} }
	| ID PushTable '(' ParamList ')' Block PopTable { $$ = $1; if($4){ asd_add_child($$,$4); }; if($6){ asd_add_child($$,$6); }; if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } 
														else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp); $1->value.value_rot = strdup(new_rot()); iloc_operations_list *iloc_list = new_iloc_operations_list(); 
														op = new_iloc_operation("nop", NULL,NULL, $1->value.value_rot) ; append_iloc_operation(iloc_list,op); 
														concat_lista(iloc_list,$6->code);
														$$->code = iloc_list; print_table();} }
	;

PushTable:  %empty { hash_da_pilha *hp = create_table(); push(stack,hp);}

PopTable:  %empty { hash_da_pilha *hp = pop(stack);}


ParamList : Param ',' ParamList { $$ = $1; asd_add_child($$,$3); }
	| Param { $$ = $1; }
	;

Param : Type ID{ $$ = $2; }
	;

Block : '{' CommandList '}'  { if($2){ $$ = $2; } }
	| '{' '}' { $$ = NULL; }
	;

CommandList : Command ';' CommandList { if($1){ $$ = $1; }; if($3){ asd_add_child($$,$3); }; }
	| Command ';' { if($1){ $$ = $1; }; }

Command : Flow { $$ = $1; }
	| DecLocal { $$ = $1; }
	| Atrib { $$ = $1; }
	| Ret { $$ = $1; }
	| FuncCall { $$ = $1; }
	| Block { $$ = $1; }
	;
	
DecLocal: Type VarListLocal { if($2){ $$ = $2; } }

VarListLocal : ID ',' VarListLocal { $$ = $3;  if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);}  }
        | ID TK_OC_LE Lit ',' VarListLocal { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $5);   if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);}  }
		| ID TK_OC_LE Lit { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3);  if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);}   }
		| ID { $$ = $1;  if(search_Pilha(stack,$1->value.value.valueChar) != NULL) { return ERR_DECLARED; } else{hash_da_pilha *hp = pop(stack); hash_table_insert(hp->hash_table,&($1->value)); push(stack,hp);}   }
		;


Atrib : ID '=' Expr { $$ = asd_new("="); asd_add_child($$, $1); asd_add_child($$,$3); if(search_Pilha(stack,$1->value.value.valueChar) == NULL) { exit(ERR_UNDECLARED); }}
	| ID '[' ArrayDim ']' '=' Expr { $$ = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child($$, col); asd_add_child($$, $6); asd_add_child(col, $1); asd_add_child(col,$3); if(search_Pilha(stack,$1->value.value.valueChar) == NULL) { return ERR_UNDECLARED; exit(ERR_UNDECLARED);}}
	;

Flow : TK_PR_WHILE '(' Expr ')' Block { $$ = asd_new("while"); asd_add_child($$, $3); if($5){ asd_add_child($$, $5); }
												char *opaco; char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); 
												$$->temp = new_temp(); char *tempoopaco = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); 
												op = new_iloc_operation("nop", NULL,NULL, label_verdade) ; append_iloc_operation(iloc_list,op);
												op = new_iloc_operation("loadI", "0",NULL, $$->temp) ; append_iloc_operation(iloc_list,op); 
												op = new_iloc_operation("cmp_NE", $3->temp,$$->temp, opaco) ; append_iloc_operation(iloc_list,op);
												concat_lista(iloc_list, $5->code);
												op = new_iloc_operation("cbr", opaco,label_verdade, label_falso); append_iloc_operation(iloc_list,op);
												op = new_iloc_operation("nop", NULL,NULL, label_falso) ; append_iloc_operation(iloc_list,op);
												$$->code = iloc_list;}
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block  { $$ = asd_new("if"); asd_add_child($$, $3); if($6){ asd_add_child($$, $6); } 
												char *opaco; char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); 
												$$->temp = new_temp(); char *tempoopaco = new_temp();  iloc_operations_list *iloc_list = new_iloc_operations_list(); 
												op = new_iloc_operation("loadI", "0",NULL, $$->temp) ; append_iloc_operation(iloc_list,op); 
												op = new_iloc_operation("cmp_NE", $3->temp,$$->temp, opaco) ; append_iloc_operation(iloc_list,op);
												op = new_iloc_operation("cbr", opaco,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
												op = new_iloc_operation("nop", NULL,NULL, label_verdade) ; append_iloc_operation(iloc_list,op);
												concat_lista(iloc_list, $6->code);
												op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
												op = new_iloc_operation("nop", NULL,NULL, label_falso) ; append_iloc_operation(iloc_list,op);
												$$->code = iloc_list; } 
	| TK_PR_IF '(' Expr ')' TK_PR_THEN Block TK_PR_ELSE Block { $$ = asd_new("if"); asd_add_child($$, $3); if($6){ asd_add_child($$, $6); }; if($8){ asd_add_child($$, $8); } 
																char *opaco; char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); 
																$$->temp = new_temp(); char *tempoopaco = new_temp();  iloc_operations_list *iloc_list = new_iloc_operations_list(); 
																op = new_iloc_operation("loadI", "0",NULL, $$->temp) ; append_iloc_operation(iloc_list,op); 
																op = new_iloc_operation("cmp_NE", $3->temp,$3->temp, opaco) ; append_iloc_operation(iloc_list,op);
																op = new_iloc_operation("cbr", opaco,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
																op = new_iloc_operation("nop", NULL,NULL, label_verdade) ; append_iloc_operation(iloc_list,op);
																concat_lista(iloc_list, $6->code);
																op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
																concat_lista(iloc_list, $8->code);
																op = new_iloc_operation("nop", NULL,NULL, label_falso) ; append_iloc_operation(iloc_list,op);
																op = new_iloc_operation("nop", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
																$$->code = iloc_list;}
	;

Ret : TK_PR_RETURN Expr { $$ = asd_new("return"); asd_add_child($$, $2); op = new_iloc_operation("jump", NULL ,NULL, $2->temp) ; append_iloc_operation(iloc_list,op); $$->code = iloc_list; } // Para o comando de retorno deve ser utilizado o lexema correspondente. ???
	;

FuncCall : ID '(' ExprList ')' { $$ = $1; asd_add_child($$, $3); if(search_Pilha(stack,$1->value.value.valueChar) == NULL) { return ERR_UNDECLARED; }	
									  else{print_table(); value = search_Pilha(stack,$1->value.value.valueChar);iloc_list = new_iloc_operations_list(); op = new_iloc_operation("jumpI", NULL,NULL, value->value_rot) ; append_iloc_operation(iloc_list,op); $$->code = iloc_list; }  }

	| ID '(' ')' { $$ = $1; if(search_Pilha(stack,$1->value.value.valueChar) == NULL) { return ERR_UNDECLARED; } else{ print_table(); value = search_Pilha(stack,$1->value.value.valueChar);iloc_list = new_iloc_operations_list(); op = new_iloc_operation("jumpI", NULL,NULL, value->value_rot) ; append_iloc_operation(iloc_list,op); $$->code = iloc_list;}  }
	;



Expr : Expr TK_OC_OR T  { $$ = asd_new("||"); asd_add_child($$, $1); asd_add_child($$, $3); 
											  $$->temp = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("or", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op); concat_lista(iloc_list, $1->code); concat_lista(iloc_list, $3->code); $$->code = iloc_list; }
	| T { $$ = $1; }
T : T TK_OC_AND F { $$ = asd_new("&&"); asd_add_child($$, $1); asd_add_child($$, $3); 
										$$->temp = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("and", $1->temp,$3->temp, $$->temp) ; concat_lista(iloc_list, $1->code); concat_lista(iloc_list, $3->code); append_iloc_operation(iloc_list,op); $$->code = iloc_list;}
	| F { $$ = $1; }
F : F TK_OC_EQ G { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); 
									   $$->temp = new_temp(); char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); iloc_operations_list *iloc_list;
									  op = new_iloc_operation("cmp_EQ", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("cbr", $$->temp,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_verdade, "loadI","1", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_falso, "loadI","0", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("nop", label_depois,NULL, NULL) ; append_iloc_operation(iloc_list,op);
									   concat_lista(iloc_list, $1->code);
									   concat_lista(iloc_list, $3->code);
									   $$->code = iloc_list;}
	| F TK_OC_NE G { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); 
										$$->temp = new_temp(); char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); iloc_operations_list *iloc_list;
									  op = new_iloc_operation("cmp_NE", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("cbr", $$->temp,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_verdade, "loadI","1", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_falso, "loadI","0", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("nop", label_depois,NULL, NULL) ; append_iloc_operation(iloc_list,op);
									   concat_lista(iloc_list, $1->code);
									   concat_lista(iloc_list, $3->code);
									   $$->code = iloc_list;}
	| G { $$ = $1; }
G : G TK_OC_LE I { $$ = asd_new("<=");  asd_add_child($$, $1); asd_add_child($$, $3); 
										$$->temp = new_temp(); char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); iloc_operations_list *iloc_list;
									  op = new_iloc_operation("cmp_LE", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("cbr", $$->temp,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_verdade, "loadI","1", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_falso, "loadI","0", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("nop", label_depois,NULL, NULL) ; append_iloc_operation(iloc_list,op);
									   concat_lista(iloc_list, $1->code);
									   concat_lista(iloc_list, $3->code);
									   $$->code = iloc_list;}
	| G TK_OC_GE I { $$ = asd_new(">=");	asd_add_child($$, $1); asd_add_child($$, $3); 
											$$->temp = new_temp(); char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); iloc_operations_list *iloc_list;
									  op = new_iloc_operation("cmp_GE", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("cbr", $$->temp,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_verdade, "loadI","1", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_falso, "loadI","0", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("nop", label_depois,NULL, NULL) ; append_iloc_operation(iloc_list,op);
									   concat_lista(iloc_list, $1->code);
									   concat_lista(iloc_list, $3->code);
									   $$->code = iloc_list;}
	| G '>' I { $$ = asd_new(">"); asd_add_child($$, $1); asd_add_child($$, $3); 
										$$->temp = new_temp(); char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); iloc_operations_list *iloc_list;
									  op = new_iloc_operation("cmp_GT", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("cbr", $$->temp,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_verdade, "loadI","1", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_falso, "loadI","0", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("nop", label_depois,NULL, NULL) ; append_iloc_operation(iloc_list,op);
									   concat_lista(iloc_list, $1->code);
									   concat_lista(iloc_list, $3->code);
									   $$->code = iloc_list;}
	| G '<' I { $$ = asd_new("<"); asd_add_child($$, $1); asd_add_child($$, $3); 
										$$->temp = new_temp(); char *label_verdade,*label_falso,*label_depois; label_verdade = new_rot(); label_falso = new_rot(); label_depois = new_rot(); iloc_operations_list *iloc_list;
									  op = new_iloc_operation("cmp_LT", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("cbr", $$->temp,label_verdade, label_falso) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_verdade, "loadI","1", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("jumpI", NULL,NULL, label_depois) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation(label_falso, "loadI","0", $$->temp) ; append_iloc_operation(iloc_list,op);
									  op = new_iloc_operation("nop", label_depois,NULL, NULL) ; append_iloc_operation(iloc_list,op);
									   concat_lista(iloc_list, $1->code);
									   concat_lista(iloc_list, $3->code);
									   $$->code = iloc_list;}
	| I { $$ = $1; }
I : I '+' J { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $3);
								 $$->temp = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("add", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op); concat_lista(iloc_list, $1->code); concat_lista(iloc_list, $3->code); $$->code = iloc_list; 
								 } //$1.cod 
	| I '-' J { $$ = asd_new("-");  asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $3);
									$$->temp = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("sub", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op); concat_lista(iloc_list, $1->code); concat_lista(iloc_list, $3->code); $$->code = iloc_list;
									}
	| J { $$ = $1; }
J : J '*' K { $$ = asd_new("*");	asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $3);
									$$->temp = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("mult", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op); concat_lista(iloc_list, $1->code); concat_lista(iloc_list, $3->code); $$->code = iloc_list;
									}
	| J '/' K { $$ = asd_new("/");  asd_add_child($$, $1); asd_add_child($$, $3); asd_add_child($$, $3);
									$$->temp = new_temp(); iloc_operations_list *iloc_list = new_iloc_operations_list(); op = new_iloc_operation("div", $1->temp,$3->temp, $$->temp) ; append_iloc_operation(iloc_list,op); concat_lista(iloc_list, $1->code); concat_lista(iloc_list, $3->code); $$->code = iloc_list; 
									}
	| J '%' K { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); 
	}
	| K { $$ = $1; }
K : '-' L { $$ = asd_new("-"); asd_add_child($$, $2); }
	| '!' L { $$ = asd_new("!"); asd_add_child($$, $2); }
	| L { $$ = $1; }
L : '(' Expr ')' { $$ = $2; }
	| FuncCall  { $$ = $1; }
	| ID '[' ArrayDim ']'
	| ID { $$ = $1; } 
	| Lit { $$ = $1;  }

ExprList : Expr ',' ExprList {$$ = $1; asd_add_child($$,$3);}
	| Expr { $$ = $1; }
	;


ID: TK_IDENTIFICADOR {$$ = asd_new(create_leaf($1)); $$->value = $1; }
	;


%%

int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	return 0;
}

void init(){
    stack = create_Pilha();
	hash_da_pilha *hp = create_table();
	push(stack,hp);
}