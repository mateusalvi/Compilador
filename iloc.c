#include "iloc.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
iloc_ops_list *new_iloc_ops_list();

iloc_op *new_iloc_op(char *opcode, char *r1, char *r2, char *r3) {
    iloc_op *operation = malloc(sizeof(iloc_op));
    operation->opcode = opcode;
    operation->r1 = r1;
    operation->r2 = r2;
    operation->r3 = r3;
    return operation;
}

iloc_ops_list *new_iloc_ops_list() {
    iloc_ops_list *list = malloc(sizeof(iloc_ops_list));
    list->operation = NULL;
    list->prev = NULL;
    list->next = NULL;
    list->count = 0;
    return list;
}

void append_iloc_op(iloc_ops_list *list, iloc_op *operation) {
    iloc_ops_list *node = malloc(sizeof(iloc_ops_list));
    node->operation = operation;
    node->next = NULL;
    node->prev = list;
    list->next = node;
    list->count++;
}

// Função para gerar um nome de rótulo único
char* new_rot() {
    static int rot_count = 0; // contador para gerar rótulos únicos
    char* rot = (char*) malloc(MAX_LABEL_LEN * sizeof(char));
    if (rot == NULL) {
        printf("Erro: não foi possível alocar memória para o rótulo.\n");
        exit(1);
    }
    snprintf(rot, MAX_LABEL_LEN, "L%d", rot_count++);
    return rot;
}

char* new_temp() {
    static int temp_count = 0; // contador para gerar temporários únicos
    char* temp = (char*) malloc(MAX_TEMP_LEN * sizeof(char));
    if (temp == NULL) {
        printf("Erro: não foi possível alocar memória para o temporário.\n");
        exit(1);
    }
    snprintf(temp, MAX_TEMP_LEN, "r%d", temp_count++);
    return temp;
}

void print_iloc_list(iloc_ops_list *list)
{
    if(list != NULL)
    {
        printf("Operation: %s. R1: %s, R2: %s, R3: %s.", list->operation->opcode, list->operation->r1, list->operation->r2, list->operation->r3);
        
        if(list->next != NULL)           //essa é a recursão, se o print estiver na ordem errada (printando o programa ao contrario),
            print_iloc_list(list->next); //joga ela pra cima do prinf                                
    }
}

void concat_lista(iloc_ops_list *list1 ,iloc_ops_list *list2)
{
	while (list2->next != NULL) 
	{
	  append_iloc_op(list1, list2->operation);
	  list2 = list2->prox;
	}
}

void print_iloc_ops_list(iloc_ops_list *list, char* filename) {
    FILE *fp;
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo %s.\n", filename);
        return;
    }

    fprintf(fp, "Lista de Operações:\n");
    iloc_ops_list *current = list;
    while (current != NULL) {
        iloc_op *operation = current->operation;
        fprintf(fp, "%s %s,%s => %s,%s,%s\n", operation->opcode, operation->r1, operation->r2, operation->r3, operation->r4, operation->r5);
        current = current->next;
    }

    fclose(fp);
}


void print_code_tree(void* arvore){
    asd_tree_t *tree = (asd_tree_t *) arvore;
	print_list_ilocs(arvore->code);
	print_iloc_ops_list(arvore->code,"saida");
}