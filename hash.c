#include "hash.h"

#define HASH_SIZE 997

static hash_node_t *table[HASH_SIZE];

void ht_init() {
    memset(table, 0, sizeof(hash_node_t*) * HASH_SIZE);
}

unsigned int ht_hash(char *key) {
    unsigned int hash = 0;
    int i;
    for (i = 0; key[i]; i++) {
        hash = (hash << 4) + key[i];
        unsigned int g = hash & 0xF0000000;
        if (g != 0) {
            hash ^= g >> 24;
            hash &= ~g;
        }
    }
    return hash % HASH_SIZE;
}

void ht_insert(char *key, value_t valor_lexico) {
    unsigned int h = ht_hash(key);
    hash_node_t *node = (hash_node_t*) malloc(sizeof(hash_node_t));
    if (!node) {
        fprintf(stderr, "Error: out of memory\n");
        exit(-1);
    }
    node->key = strdup(key);
    node->valor_lexico = valor_lexico;
    node->next = table[h];
    table[h] = node;
}

value_t ht_search(char *key) {
    unsigned int h = ht_hash(key);
    hash_node_t *node;
    for (node = table[h]; node; node = node->next) {
        if (strcmp(node->key, key) == 0)
            return node->valor_lexico;
    }
    value_t v;
    v.type = -1; // not found
    return v;
}

void ht_print() {
    int i;
    printf("Hash table:\n");
    for (i = 0; i < HASH_SIZE; i++) {
        if (table[i]) {
            printf("%d: ", i);
            hash_node_t *node = table[i];
            while (node) {
                printf("(%s, %d, %d) ", node->key, node->valor_lexico.type, node->valor_lexico.atLine);
                node = node->next;
            }
            printf("\n");
        }
    }
}

void stack_push(Stack **stack, hash_node_t *ht) {
    Stack *new_node = (Stack*) malloc(sizeof(Stack));
    if (!new_node) {
        fprintf(stderr, "Error: out of memory\n");
        exit(-1);
    }
    new_node->ht = ht;
    new_node->next = *stack;
    *stack = new_node;
}

hash_node_t *stack_pop(Stack **stack) {
    if (!*stack)
        return NULL;
    Stack *top = *stack;
    hash_node_t *ht = top->ht;
    *stack = top->next;
    free(top);
    return ht;
}

hash_node_t *stack_search(Stack **stack, char *key) {
    Stack *node = *stack;
    while (node) {
        hash_node_t *ht = node->ht;
        value_t value = ht_search(ht, key);
        if (value.type != -1)
            return ht;
        node = node->next;
    }
    return NULL;
}