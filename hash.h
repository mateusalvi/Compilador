#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "asd.h"
#define TABLE_SIZE 20



typedef struct hash_da_pilha {
	
	value_t * hash_table[TABLE_SIZE];
	
} hash_da_pilha;

unsigned int hash(char *key);

void init_hash_table();

void print_table();

bool hash_table_insert(value_t *v);

value_t *hash_table_lookup (char *key);

char* generate_random_key(int length);

#endif