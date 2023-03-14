#include "hash.h"
#include "asd.h"

#define CAPACITY 50000 // Size of the HashTable.
#define MAX_KEY 256

value_t * hash_table[TABLE_SIZE];


 unsigned int hash(char *key) {
	 int length = strnlen(key, MAX_KEY);
	 unsigned int hash_value = 0;
	 for (int i=0; i < length; i++) {
		 hash_value += key[i];
		 hash_value = (hash_value * key[i]) % TABLE_SIZE;
	 }
	 return hash_value;
 }
 
 void init_hash_table() {
	 for (int i=0; i < TABLE_SIZE; i++) {
		 hash_table[i] = NULL;
	 }
 }
	 
	 void print_table() {
		 for (int i=0; i < TABLE_SIZE; i++) {
			 if (hash_table[i] == NULL) {
				 printf("\t%i\t---\n");
			 } else {
				 printf("\t%i\t%s\n", hash_table[i]->key);
			 }
		 }
	 }
	 
	 bool hash_table_insert(value_t *v) {
		 if (v == NULL) return false;
		 int index = hash(v->key);
		 if (hash_table[index] != NULL) {
			 return false;
		 }
		 hash_table[index] = v;
		 return true;
	 }
	 
	 value_t *hash_table_lookup (char *key) {
		 int index = hash(key);
		 if (hash_table[index] != NULL &&
		 strncmp(hash_table[index]->key, key, TABLE_SIZE)==0) {
			 return hash_table[index];
		 } else {
			 return NULL;
		 }
	 }