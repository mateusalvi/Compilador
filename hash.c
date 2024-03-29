#include "hash.h"
#include "asd.h"

#define MAX_KEY 256


static int desloc;

 unsigned int hash(char *key) {
	 int length = strnlen(key, MAX_KEY);
	 unsigned int hash_value = 0;
	 for (int i=0; i < length; i++) {
		 hash_value += key[i];
		 hash_value = (hash_value * key[i]) % TABLE_SIZE;
	 }
	 return hash_value;
 }
 
hash_da_pilha* create_table() {
	 hash_da_pilha* ht= malloc(sizeof(hash_da_pilha));
	 ht->desloc = 0;
	 value_t* hash_table[TABLE_SIZE];
	 for (int i=0; i < TABLE_SIZE; i++) {
		 ht->hash_table[i] = NULL;
	 }
	 
	 printf("e is of type %s\n", sizeof(ht) == sizeof(hash_da_pilha*) ? "hash" : "unknown");
	 return ht;
 }
 
	 
	 void print_table() {
		 /*for (int i=0; i < TABLE_SIZE; i++) {
			 if (hash_table[i] == NULL) {
				 printf("\t%i\t---\n",i);
			 } else {
				 printf("\t%i\t%s",i, hash_table[i]->value.valueChar); printf("               atLine: %d, value_t value: %d\n", hash_table[i]->atLine, hash_table[i]->type);
			 }
		 }*/
	 }
	 
	 bool hash_table_insert(value_t *hash_table[TABLE_SIZE], value_t *s) {
		 if (s == NULL) return false;
		 printf("%s", s->value.valueChar);
		 int index = hash(s->value.valueChar);
		 if (hash_table[index] != NULL) {
			 return false;
		 }
		hash_table[index] = malloc(sizeof(value_t)); // Allocate memory for the struct
		memcpy(hash_table[index], s, sizeof(value_t)); // Copy the struct into the allocated memory
		hash_table[index]->value.valueChar = malloc(strlen(s->value.valueChar) + 1); // Allocate memory for the string
		strcpy(hash_table[index]->value.valueChar, s->value.valueChar); // Copy the string into the allocated memory
		hash_table[index]->key = index;
		printf("Success!\n");
		return true;
	 }
	 
	 value_t *hash_table_lookup (value_t* hash_table[TABLE_SIZE],char *key) {
		 int index = hash(key);
		 printf("%d\n", index);
		 if (hash_table[index] != NULL &&
		 strncmp(hash_table[index]->value.valueChar, key, TABLE_SIZE)==0) {
			 return hash_table[index];
		 } else {
			 return NULL;
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