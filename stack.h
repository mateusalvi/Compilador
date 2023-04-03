#include "hash.h"

typedef struct nodo {
	
	hash_da_pilha hash;
	struct nodo *next;
}Nodo;
	
	typedef struct pilha {
		Nodo *cabeça;
		int tamanho;
	}Pilha;
	
	/*Receita Pilha
	cria uma int main() no .c
	instancia uma tabela
	instancia uma pilha
	instancia um elemento da tabela
	função de printar pilha/tabela/elemento