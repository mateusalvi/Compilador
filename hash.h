#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "asd.h"
#define SIZE 1000
union value_u{
    int intValue;
    float floatValue;
    char charValue;
};

// typedef struct ItemContent
// {
//     int atLine;
//     int type;
// 	float size;
//     union value_u value;
// } ItemContent;

typedef struct Ht_item
{
    char* key;
    int atLine;
    int type;
	float size;
    char* value;
    //union value_u value;
    //ItemContent** Ht_item_content;
} Ht_item;

typedef struct LinkedList
{
    struct Ht_item *item;
    struct LinkedList *next;
} LinkedList;

typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item **items;
    LinkedList **overflow_buckets;
    int size;
    int count;
} HashTable;

unsigned long hash_function(char* str);

LinkedList *allocate_list();

LinkedList *linkedlist_insert(LinkedList *list, Ht_item *item);

Ht_item *linkedlist_remove(LinkedList *list);

void free_linkedlist(LinkedList *list);

LinkedList **create_overflow_buckets(HashTable *table);

void free_overflow_buckets(HashTable *table);

Ht_item* create_item(char* key, value_t valor_lexico);

HashTable* create_table(int size);

void free_item(Ht_item* item);

void free_table(HashTable* table);

void handle_collision(HashTable *table, unsigned long index, Ht_item *item);

void ht_insert(char* key, value_t valor_lexico);

char* ht_search(HashTable* table, char* key);

void ht_delete(HashTable *table, char *key);

void print_search(HashTable *table, char *key);

void print_table(HashTable *table);

bool search_stack(Ht_item *item);


HashTable *HashTableStack[SIZE];
int top = 0;

//Push a table onto stack
void push(HashTable *table);

//Pop a table from stack
void pop();

//Print the whole stack to console
void show();

//Free stack alloc from memory
void Free_Hash_Stack();

#endif