#include "hash.h"
#include "asd.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashAddress(char *text){
    int address = 1;

    unsigned long i = 0;
    for (int j = 0; text[j]; j++)
        i += text[j];

    return i % HASH_SIZE;
}

HASH_ENT* create_item(valor_t value){
    // Creates a pointer to a new HashTable item.
    HASH_ENT* item = (HASH_ENT*) malloc(sizeof(HASH_ENT));
    int chave = hashAddress(value.value.token);
    item->chave = chave;
    item->valor_lexico = value;
    return item;
}

void insert_item(HASH_TABLE* table, valor_t novo_simbolo)
{
    // Creates the item.
    HASH_ENT* item = create_item(novo_simbolo);

    // Computes the index.
    int index = hashAddress(novo_simbolo.value.token);

    HASH_ENT* current_item; /* = (HASH_ENT*) malloc(sizeof(HASH_ENT));*/
    current_item = table->items[index];

    if (current_item == NULL){
        table->items[index] = item;
    }
}

void init_table(HASH_TABLE* table)
{
    // Creates a new HashTable.
    table = (HASH_TABLE*) malloc(sizeof(HASH_TABLE));
    table->size_table = HASH_SIZE;
    table->items = (HASH_ENT**) calloc(table->size_table, sizeof(HASH_ENT*));

    for (int i = 0; i < table->size_table; i++)
        table->items[i] = NULL;

}

/*
void free_item(HASH_ENT* item)
{
    // Frees an item.
    free(item->chave);
    free(item->valor_lexico);
    free(item);
}*/

void free_table(HASH_TABLE* table)
{
    // Frees the table.
    for (int i = 0; i < table->size_table; i++)
    {
        HASH_ENT* item = table->items[i];

        if (item != NULL)
            free(item);
    }

    free(table->items);
    free(table);
}

void print_table(HASH_TABLE* table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < table->size_table; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%d, Value:%s\n", i, table->items[i]->chave, table->items[i]->valor_lexico.value.token);
        }
    }

    printf("-------------------\n\n");
}

HASH_ENT* ht_search(HASH_TABLE* table, char* token)
{
    // Searches for the key in the HashTable.
    // Returns NULL if it doesn't exist.

    int index = hashAddress(token);

    HASH_ENT* item = table->items[index];

    // Provide only non-NULL values.
    if (item != NULL)
    {
        if (strcmp(item->valor_lexico.value.token, token) == 0){
            return item;
        }
    }
    return NULL;
}

HASH_TABLE* create_table(int size)
{
    // Creates a new HashTable.
    HASH_TABLE* table = (HASH_TABLE*) malloc(sizeof(HASH_TABLE));
    table->size_table = size;
    table->items = (HASH_ENT**) calloc(table->size_table, sizeof(HASH_ENT*));

    for (int i = 0; i < table->size_table; i++)
        table->items[i] = NULL;
    return table;
}

void calcula_tamanho(valor_t valor_lexico){
	switch(valor_lexico.tipo){
		case TK_LIT_FLOAT:
			valor_lexico.tamanho = 8;
			break;
		case TK_LIT_INT:
			valor_lexico.tamanho = 4;
			break;
		case TK_LIT_CHAR:
		case TK_LIT_TRUE:
		case TK_LIT_FALSE:
			valor_lexico.tamanho = 1;
			break;
	}
}

bool search_stack(char* key) 
{    
	for(int i = top; i != -1; i--)
    {
        if(ht_search(HashTableStack[i], key))
            return true;
	}
	return false;
}

// void ht_delete(HashTable *table, value_t value)
// {
//     // Deletes an item from the table.
//     int index = hash_function(key);
//     Ht_item *item = table->items[index];
//     LinkedList *head = table->overflow_buckets[index];

//     if (item == NULL)
//     {
//         // Does not exist.
//         return;
//     }
//     else
//     {
//         if (head == NULL && strcmp(item->key, key) == 0)
//         {
//             // Collision chain does not exist.
//             // Remove the item.
//             // Set table index to NULL.
//             table->items[index] = NULL;
//             free_item(item);
//             table->count--;
//             return;
//         }
//         else if (head != NULL)
//         {
//             // Collision chain exists.
//             if (strcmp(item->key, key) == 0)
//             {
//                 // Remove this item.
//                 // Set the head of the list as the new item.
//                 free_item(item);
//                 LinkedList *node = head;
//                 head = head->next;
//                 node->next = NULL;
//                 table->items[index] = create_item(node->item->key, node->item->value->value);
//                 free_linkedlist(node);
//                 table->overflow_buckets[index] = head;
//                 return;
//             }

//             LinkedList *curr = head;
//             LinkedList *prev = NULL;

//             while (curr)
//             {
//                 if (strcmp(curr->item->key, key) == 0)
//                 {
//                     if (prev == NULL)
//                     {
//                         // First element of the chain.
//                         // Remove the chain.
//                         free_linkedlist(head);
//                         table->overflow_buckets[index] = NULL;
//                         return;
//                     }
//                     else
//                     {
//                         // This is somewhere in the chain.
//                         prev->next = curr->next;
//                         curr->next = NULL;
//                         free_linkedlist(curr);
//                         table->overflow_buckets[index] = head;
//                         return;
//                     }
//                 }

//                 curr = curr->next;
//                 prev = curr;
//             }
//         }
//     }
// }

void print_search(HashTable *table, char *key)
{
    char *val;

    if ((val = ht_search(table, key)) == NULL)
    {
        printf("Key:%s does not exist\n", key);
        return;
    }
    else
    {
        printf("Key:%s, Value:%s\n", key, val);
    }
}

void print_table(HashTable *table)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < table -> size; i++)
    {
        if (table -> items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table -> items[i] -> key, table -> items[i] -> value);
        }
    }

    printf("-------------------\n\n");
}

void push(HashTable *table)
{
    if (top == SIZE - 1)
    {
        printf("\nHashTable StackOverflow!");
        exit(0);
    }
    else
    {
        top += top;
        HashTableStack[top] = table;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nHashTable StackUnderflow!!");
        exit(0);
    }
    else
    {
        HashTableStack[top] = NULL;
        top -= top;
    }
}

void print_stack()
{
    printf("\nStack \n-------------------------------------------\n");
	for (int j = top; j >= 0; j--)
	{ printf("\nHash Table\n-------------------\n");
		printf("Hash Table index = %d", j);
		HashTable table = *HashTableStack[j];
		for (int i = 0; i < table.size; i++)
		{
			if (table.items[i])
			{
				printf("Index:%d, Key:%s, Value:%s\n", i, table.items[i]->key, table.items[i]->value);
			}
		}
	
		printf("-------------------\n\n");
	}
	printf("-------------------------------------------\n\n");
}

void Free_Hash_Stack()
{
    // free(HashTableStack);
}

// void show()
// {
//     if (top == -1)
//     {
//         printf("\nUnderflow!!");
//     }
//     else
//     {
//         printf("\nElements present in the stack: \n");
//         for (int i = top; i >= 0; --i)
//             printf("Index: %d, Table: %ld\n", top, (long)HashTableStack[i]);
//     }
// }