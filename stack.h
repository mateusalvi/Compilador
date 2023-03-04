#ifndef _STACK_H_
#define _STACK_H_


#define SIZE 1000

HashTable HashTableStack[SIZE];
int top = -1;

//Push a table onto stack
void push(HashTable *table);

//Pop a table from stack
void pop();

//Print the whole stack to console
void show();

//Free stack alloc from memory
void Free_Hash_Stack();

#endif