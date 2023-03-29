/*
  Função principal para realização da E3.
  Não modifique este arquivo.
*/
#include <stdio.h>
#include <stddef.h>
#include "asd.h"
#include "hash.h"


extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
void asd_print_graphviz (asd_tree_t *arvore);
void asd_free (asd_tree_t *arvore); 


int main (int argc, char **argv)
{
  top=-1;
  init_hash_table();
  int ret = yyparse(); 
  //asd_print(arvore);
  //asd_print(arvore);
  void print_table();
  arvore = NULL;
  yylex_destroy();
  return ret;
}