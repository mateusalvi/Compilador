#include "hash.h"
#include "asd.h"

#define MAX_KEY 256


value_t * hash_table[TABLE_SIZE];

hash_da_pilha * pilha[TABLE_SIZE];

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
		 printf("pq n printa");
		 for (int i=0; i < TABLE_SIZE; i++) {
			 if (hash_table[i] == NULL) {
				 printf("\t%i\t---\n",i);
			 } else {
				 printf("\t%i\t%s\n",i, hash_table[i]->value.valueChar); printf("Contents of structure are %d, %d\n", hash_table[i]->atLine, hash_table[i]->type);
			 }
		 }
	 }
	 
	 bool hash_table_insert(value_t *v) {
		 if (v == NULL) return false;
		 int index = hash(v->value.valueChar);
		 if (hash_table[index] != NULL) {
			 return false;
		 }
		 hash_table[index] = v;
		 v->key = index;
		 printf("Success!");
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
	 
	void init_stack() {
	 for (int i=0; i < TABLE_SIZE; i++) {
		 pilha[i] = NULL;
	 }
 }
 
 char* generate_random_key(int length) {
    char* key = malloc(sizeof(char) * (length + 1)); // Allocate memory for the key
    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < length; i++) {
        key[i] = 'a' + rand() % 26; // Generate a random lowercase letter
    }
    key[length] = '\0'; // Add a null terminator at the end of the string

    return key;
}