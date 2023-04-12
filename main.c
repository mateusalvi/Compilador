/*
  Função principal para realização da E3.
  Não modifique este arquivo.
*/
#include <stdio.h>
#include <stddef.h>
#include "asd.h"
#include "hash.h"
#include "iloc.h"
#include "stack.h"




extern int yyparse(void);
extern int yylex_destroy(void);
extern void init(void);
iloc_operations_list *iloc_list;
void *arvore = NULL;
void asd_print_graphviz (asd_tree_t *arvore);
void asd_free (asd_tree_t *arvore);
iloc_operation *op;
value_t *value; 
Pilha* stack;
hash_da_pilha *hp;


int main (int argc, char **argv)
{

  init();
  int ret = yyparse(); 
 // print_iloc_list(iloc_list);
  asd_print(arvore);
  //void print_table();
  arvore = NULL;
  yylex_destroy();
  return ret;
}