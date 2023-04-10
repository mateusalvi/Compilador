#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "stack.h"

int empty_Pilha(Pilha* Pilha){
     if(Pilha->cabeça == NULL)
        return 1;
     else
        return 0;
}

Pilha* create_Pilha(){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->cabeça = NULL;
    pilha->size = 0;
    return Pilha;
}

void push(Pilha* Pilha, hash_da_pilha* table){
    Nodo* new_element = malloc(sizeof(struct Nodo));
    new_element->hash->hash_table = table;
    new_element->next = Pilha->cabeça;
    Pilha->cabeça = new_element;
    Pilha->size+=1;
}


hash_da_pilha* pop(Pilha* pilha){
    if(empty_Pilha(pilha)){
        printf("pilha vazia!\n");
        exit(4);
    }
    else{
        Nodo* temp = pilha->cabeça->next;
        hash_da_pilha* table = pilha->cabeça->hash->hash_table;
        Pilha->cabeça = temp;
        Pilha->size-=1;
        return table;
    }
}



void delete_Pilha(Pilha* Pilha){
    Nodo *atual, *prox;
    atual = Pilha->cabeça->next;
    while(atual != NULL){
        prox = atual->next;
        free(atual);
        atual = prox;
    }
} //free all

void print_Pilha(Pilha* Pilha){
    Nodo *atual;
    atual = Pilha->cabeça;
    while(atual!=NULL){
        print_table(atual->hash->hash_table);
        atual = atual->next;
    }
}

value_t search_Pilha(Pilha* Pilha, char* simbolo){
    Nodo* aux;
    aux = Pilha->cabeça;
    value_t achou;
    while(aux){
        achou = hash_table_lookup(aux->hash->hash_table,simbolo);
        if(achou)
            return achou;
        aux = aux->next;
    }

    return NULL;
}


