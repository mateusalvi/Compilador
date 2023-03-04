#ifndef _ARVORE_H_
#define _ARVORE_H_

union literal {
    int valueInt;
    float valueFloat;
    char* valueChar;
  };

typedef struct value
{
  int atLine;
  int type;
  union literal value;
} value_t;

typedef struct asd_tree 
{
  char *label;
  value_t value;
  int number_of_children;
  struct asd_tree **children;
} asd_tree_t;

/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
asd_tree_t *asd_new(const char *label);

// value_t print_node (char* valor_lexico);

char* create_leaf(value_t value);

void asd_free_node(asd_tree_t *tree);

/*
 * Função asd_tree, libera recursivamente o nó e seus filhos.
 */
void asd_free(asd_tree_t *tree);

/*
 * Função asd_add_child, adiciona child como filho de tree.
 */
void asd_add_child(asd_tree_t *tree, asd_tree_t *child);

/*
 * Função asd_print, imprime recursivamente a árvore.
 */
void asd_print(asd_tree_t *tree);

/*
 * Função asd_print_graphviz, idem, em formato DOT
 */
void asd_print_graphviz (asd_tree_t *tree);
#endif //_ARVORE_H_