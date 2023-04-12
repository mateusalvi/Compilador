#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "asd.h"
#define TABLE_SIZE 1021

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

typedef struct hash_da_pilha {
	
	value_t * hash_table[TABLE_SIZE];
	int desloc;
	
} hash_da_pilha;

unsigned int hash(char *key);

void init_hash_table();

void print_table();

bool hash_table_insert(value_t *hash_table[TABLE_SIZE], value_t *s);

value_t *hash_table_lookup (value_t* hash_table[TABLE_SIZE],char *key);


char* generate_random_key(int length);

#endif