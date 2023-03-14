#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "asd.h"
#define TABLE_SIZE 1000

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_ARRAY 21 //2.3
#define ERR_FUNCTION 22 //2.3
#define ERR_CHAR_TO_INT 31 //2.4
#define ERR_CHAR_TO_FLOAT 32 //2.4
#define ERR_CHAR_TO_BOOL 33 //2.4
#define ERR_CHAR_VECTOR 34 //2.4
#define ERR_X_TO_CHAR 35 //2.4

typedef struct node {
  char* key;
  value_t value;
  struct node* next;
} node_t;

typedef struct hash_table {
  node_t** items;
  int size;
} hash_table_t;

hash_table_t* create_table();
void free_table(hash_table_t* table);
unsigned int hash(const char* key);
node_t* create_node(const char* key, value_t value);
void free_node(node_t* node);
void ht_insert(hash_table_t* table, const char* key, value_t value);
node_t* ht_search(hash_table_t* table, const char* key);
void ht_print(hash_table_t* table);


void stack_push(Stack **stack, hash_node_t *ht);

hash_node_t *stack_pop(Stack **stack);

hash_node_t *stack_search(Stack **stack, char *key);

#endif