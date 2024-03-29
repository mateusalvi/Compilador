#include <stdio.h>
#include "asd.h"
#define ARQUIVO_SAIDA "saida.dot"

asd_tree_t *asd_new(const char *label)
{
  asd_tree_t *ret = NULL;
  ret = calloc(1, sizeof(asd_tree_t));

  if (ret != NULL)
  {
    ret->label = strdup(label);
    ret->number_of_children = 0;
    ret->children = NULL;
  }

  return ret;
}

void asd_free(asd_tree_t *tree)
{
  if (tree != NULL)
  {
    int i;
    for (i = 0; i < tree->number_of_children; i++){
      //printf("Current children in free: %p\n", tree->children[i]);
      asd_free(tree->children[i]);
    }

    //printf("Freeing node with label: %s, at adr: %p\n", tree->label, tree);
    free(tree->children);
    free(tree->label);
    free(tree);
  }
}

void asd_free_node(asd_tree_t *tree)
{
    free(tree->children);
    free(tree->label);
    free(tree);
}

char* create_leaf(value_t value)
{
    return value.value.valueChar;
}

// char* return_value(value_t value)
// {
//   switch (value.type)
//   {
//   case 0:
//     return value.
//     break;
  
//   default:
//     break;
//   }
// }

void asd_add_child(asd_tree_t *tree, asd_tree_t *child)
{
  if (tree != NULL && child != NULL)
  {
    //printf("Adicionando child com label %s, que contem %d filhos \n", tree->label, tree->number_of_children);
    tree->number_of_children++;
    tree->children = realloc(tree->children, tree->number_of_children * sizeof(asd_tree_t*));
    tree->children[tree->number_of_children-1] = child;
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p / %p.\n", __FUNCTION__, tree, child);
  }
}

static void _asd_print (FILE *foutput, asd_tree_t *tree, int profundidade)
{
  int i;

  if (tree != NULL)
  {
    fprintf(foutput, "%d%*s: Nó '%s' tem %d filhos:\n", profundidade, profundidade*2, "", tree->label, tree->number_of_children);
    for (i = 0; i < tree->number_of_children; i++){
      _asd_print(foutput, tree->children[i], profundidade+1);
    }
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_print(asd_tree_t *tree)
{
  //FILE *foutput = stderr;
  FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");

  if (tree != NULL)
  {
    _asd_print(foutput, tree, 0);
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

// static void _asd_print_graphviz (FILE *foutput, asd_tree_t *tree)
// {
//   int i;

//   if (tree != NULL)
//   {
//     fprintf(foutput, "  %ld [ label=\"%s\" ];\n", (long)tree, tree->label);
//     for (i = 0; i < tree->number_of_children; i++){
//       fprintf(foutput, "  %ld -> %ld;\n", (long)tree, (long)tree->children[i]);
//       _asd_print_graphviz(foutput, tree->children[i]);
//     }
//   }
//   else
//   {
//     printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
//   }
// }

static void _asd_print_graphviz_adr (FILE *foutput, asd_tree_t *tree)
{
  int i;

  if (tree != NULL)
  {
    for (i = 0; i < tree->number_of_children; i++){
      if(tree->children[i] != NULL)
      {
        fprintf(foutput, "%p, %p\n", tree, tree->children[i]);
        _asd_print_graphviz_adr(foutput, tree->children[i]);
      }
    }
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

static void _asd_print_graphviz_lbl (FILE *foutput, asd_tree_t *tree)
{
  int i;

  if (tree != NULL)
  {
    fprintf(foutput, "%p [ label=\"%s\" ];\n", tree, tree->label);
    for (i = 0; i < tree->number_of_children; i++){
      if(tree->children[i] != NULL)
      {
        _asd_print_graphviz_lbl(foutput, tree->children[i]);
      }
    }
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_print_graphviz(asd_tree_t *tree)
{
  FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");
  
  if(foutput == NULL)
  {
    printf("Erro: %s não pude abrir o arquivo [%s] para escrita.\n", __FUNCTION__, ARQUIVO_SAIDA);
  }
  
  if (tree != NULL){
    fprintf(foutput, "digraph {\n");
    fprintf(foutput, "label=\"Ref\";\n");
    _asd_print_graphviz_adr(foutput, tree);
    _asd_print_graphviz_lbl(foutput, tree);
    fprintf(foutput, "}\n");
    fclose(foutput);
  }
  else
  {
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}