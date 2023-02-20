#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct asd_tree 
{
  char *label;
  int number_of_children;
  struct asd_tree **children;
} asd_tree_t;

typedef struct value
{
  int atLine;
  int type;
  union {
    int valueInt;
    float valueFloat;
    char* valueChar;
  };
} value_t;


/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
asd_tree_t *asd_new(const char *label);

value_t print_node (char* valor_lexico);

char* create_leaf(value_t value);

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
