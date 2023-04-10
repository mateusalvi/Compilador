#ifndef ILOC_H
#define ILOC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LABEL_LEN 64
#define MAX_TEMP_LEN 64

typedef struct iloc_operation {
    char *opcode;
    char *r1, *r2, *r3;
} iloc_operation;

typedef struct iloc_operations_list {
    iloc_operation *operation;
    struct iloc_operations_list *prev;
    struct iloc_operations_list *next;
    int count;
} iloc_operations_list;

iloc_operation *new_iloc_operation(char *opcode, char *r1, char *r2, char *r3);

iloc_operations_list *new_iloc_operations_list();

void append_iloc_operation(iloc_operations_list *list, iloc_operation *operation);

// Função para gerar um nome de rótulo único
char* new_rot();

void print_iloc_list(iloc_operations_list *list);

// Função para gerar um nome de temporário único
char* new_temp();

void concat_lista(iloc_operations_list *list1 ,iloc_operations_list *list2);

void print_iloc_operations_list(iloc_operations_list *list, char* filename);

#endif // ILOC_H