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

void init_Pilha(void){
    Pilha = malloc(sizeof(Pilha));
    Pilha->cabeça = NULL;
    Pilha->size = 0;
}

Pilha* create_Pilha(){
    Pilha* Pilha = malloc(sizeof(Pilha));
    Pilha->cabeça = NULL;
    Pilha->size = 0;
    return Pilha;
}

void push(Pilha* Pilha, hash_da_pilha* table){
    Nodo* new_element = malloc(sizeof(struct Nodo));
    new_element->data = table;
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
        hash_da_pilha* table = Pilha->cabeça->data;
        Pilha->cabeça = temp;
        Pilha->size-=1;
        return table;
    }
}

Nodo* retrieve(Pilha* Pilha, int level){
    if (Pilha->size < level)
        printf("Pilha isn't that long yet\n");
    Nodo* temp = Pilha->cabeça;
    level -= 1;
    while(level > 0){
        temp = temp->next;
        level--;
    }
    return temp;
} //get something below

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
        print_table(atual->data);
        atual = atual->next;
    }
}

value_t search_Pilha(Pilha* Pilha, char* simbolo){
    Nodo* aux;
    aux = Pilha->cabeça;
    value_t achou;
    while(aux){
        achou = hash_table_lookup(aux->hash,simbolo);
        if(achou)
            return achou;
        aux = aux->next;
    }

    return NULL;
}


