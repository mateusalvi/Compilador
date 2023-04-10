/*
  Função principal para realização da E3.
  Não modifique este arquivo.
*/
#include <stdio.h>
#include <stddef.h>
#include "asd.h"
#include "hash.h"
#include "iloc.h"




extern int yyparse(void);
extern int yylex_destroy(void);
iloc_operations_list *iloc_list;
void *arvore = NULL;
void asd_print_graphviz (asd_tree_t *arvore);
void asd_free (asd_tree_t *arvore); 


int main (int argc, char **argv)
{

  init_hash_table();
  int ret = yyparse(); 
 // print_iloc_list(iloc_list);
  asd_print(arvore);
  print_code_tree(arvore);
  //void print_table();
  arvore = NULL;
  yylex_destroy();
  return ret;
}