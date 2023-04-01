#include "iloc.h"

iloc_operations_list *new_iloc_operations_list();

iloc_operation *new_iloc_operation(char *opcode, char *r1, char *r2, char *r3) {
    iloc_operation *operation = malloc(sizeof(iloc_operation));
    operation->opcode = opcode;
    operation->r1 = r1;
    operation->r2 = r2;
    operation->r3 = r3;
    return operation;
}

iloc_operations_list *new_iloc_operations_list() {
    iloc_operations_list *list = malloc(sizeof(iloc_operations_list));
    list->operation = NULL;
    list->prev = NULL;
    list->next = NULL;
    list->count = 0;
    return list;
}

void append_iloc_operation(iloc_operations_list *list, iloc_operation *operation) {
    iloc_operations_list *node = malloc(sizeof(iloc_operations_list));
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

void print_iloc_list(iloc_operations_list *list)
{
    if(list != NULL)
    {
        printf("Operation: %s. R1: %s, R2: %s, R3: %s.", list->operation->opcode, list->operation->r1, list->operation->r2, list->operation->r3);
        
        if(list->next != NULL)           //essa é a recursão, se o print estiver na ordem errada (printando o programa ao contrario),
            print_iloc_list(list->next); //joga ela pra cima do prinf                                
    }
}