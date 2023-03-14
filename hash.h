#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "asd.h"
#define SIZE 1000

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

#ifndef HASH_HEADER
#define HASH_HEADER
#define HASH_SIZE 997

typedef struct hash_ent{
   valor_t valor_lexico; // dados acerca do simbolo
   int chave;
   int desloc;
}HASH_ENT;

typedef struct hash_table{
    int size_table;
    HASH_ENT **items;
}HASH_TABLE;

int hashAddress(char*);
//void init_table(HASH_TABLE*);
HASH_TABLE* create_table(int);
HASH_ENT* create_item(valor_t);
void insert_item(HASH_TABLE*,valor_t);
void calcula_tamanho(valor_t);
HASH_ENT* ht_search(HASH_TABLE*,char*);
void print_table(HASH_TABLE*);
void free_item(HASH_ENT*);
void free_table(HASH_TABLE*);


void print_table(HashTable *table);

bool search_stack(char *key);


//Push a table onto stack
void push(HashTable *table);

//Pop a table from stack
void pop();

//Print the whole stack to console
void show();

//Free stack alloc from memory
void Free_Hash_Stack();

#endif