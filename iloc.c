#include "iloc.h"

iloc_operations_list *new_iloc_operations_list();

iloc_operation *new_iloc_operation(char *opcode, char *src1, char *src2, char *src3, char *dst1, char *dst2, char *dst3, char *label) {
    iloc_operation *operation = malloc(sizeof(iloc_operation));
    operation->opcode = opcode;
    operation->src1 = src1;
    operation->src2 = src2;
    operation->src3 = src3;
    operation->dst1 = dst1;
    operation->dst2 = dst2;
    operation->dst3 = dst3;
    operation->label = label;
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
char* new_label() {
    static int label_count = 0; // contador para gerar rótulos únicos
    char* label = (char*) malloc(MAX_LABEL_LEN * sizeof(char));
    if (label == NULL) {
        printf("Erro: não foi possível alocar memória para o rótulo.\n");
        exit(1);
    }
    snprintf(label, MAX_LABEL_LEN, "L%d", label_count++);
    return label;
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