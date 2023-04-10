#include "hash.h"

typedef struct nodo {
	
	hash_da_pilha hash;
	struct nodo *next;
}Nodo;
	
	typedef struct pilha {
		Nodo *cabeça;
		int tamanho;
	}Pilha;
	
	
int empty_Pilha(Pilha* Pilha);

void init_Pilha(void);

Pilha* create_Pilha();

void push(Pilha* Pilha, HASH_TABLE* table);

hash_da_pilha* pop(Pilha* pilha);

Nodo* retrieve(Pilha* Pilha, int level);

void delete_Pilha(Pilha* Pilha);

void print_Pilha(Pilha* Pilha);

value_t search_Pilha(Pilha* Pilha, char* simbolo);



	/*Receita Pilha
	cria uma int main() no .c
	instancia uma tabela
	instancia uma pilha
	instancia um elemento da tabela
	função de printar pilha/tabela/elemento