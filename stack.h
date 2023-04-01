#include "hash.h"

typedef struct nodo {
	
	hash_da_pilha hash;
	struct nodo *next;
}Nodo;
	
	typedef struct pilha {
		Nodo *cabeça;
		int tamanho;
	}Pilha;