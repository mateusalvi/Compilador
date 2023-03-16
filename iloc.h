#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LABEL_LEN 64
#define MAX_TEMP_LEN 64

typedef struct iloc_operation {
    char *opcode;
    char *src1, *src2, *src3;
    char *dst1, *dst2, *dst3;
    char *label;
} iloc_operation;

typedef struct iloc_operations_list {
    iloc_operation *operation;
    struct iloc_operations_list *prev;
    struct iloc_operations_list *next;
    int count;
} iloc_operations_list;

iloc_operation *new_iloc_operation(char *opcode, char *src1, char *src2, char *src3, char *dst1, char *dst2, char *dst3, char *label);

iloc_operations_list *new_iloc_operations_list();

void append_iloc_operation(iloc_operations_list *list, iloc_operation *operation);

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

// Função para gerar um nome de temporário único
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