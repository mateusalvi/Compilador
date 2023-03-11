#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "stack.h"

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
        top -= top;
    }
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

bool search_stack(Ht_item item) 
{
	for(i = size; i != -1; i--;){
	if(htsearch(stack[i],item.value)
		return True;
	}
	return False;
}