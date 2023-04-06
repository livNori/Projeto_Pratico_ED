#include "lista.h"
#include <stdlib.h>
#include <stdio.h>


void inicializa(lista *p){
	struct node *n = malloc(sizeof(struct node));
	n->next = n->prev = p->sentinela = n;
	p->quantidade = 0;
}		


int vazia(lista *p){
	return p->sentinela->next == p->sentinela;
}								


void destuir(lista *p){
	
	while(!vazia(p))
		retira(p);
	
	free(p->sentinela);
}

void limpar(lista *p){
	
	while(!vazia(p))
		retira(p);

}


int cheia(lista *p){
	/*verificar se o tamanho máximo foi atingido 
	return ;*/
}								


unsigned tamanho(lista *p){
	//retorna o número de elementos na lista
	return p->quantidade;
}				


void insere(lista *p, T data){	
	struct node *n = malloc(sizeof(struct node));
	n->data = data;
	n->next = p->sentinela;
	n->prev = p->sentinela->prev;
	p->sentinela->prev = n;
	n->prev->next = n;
	p->quantidade++;
}		


void retira(lista *p){	
	struct node *n = p->sentinela->next;
	if( n != p->sentinela ) { // lista vazia
		n->prev->next = n->next;
		n->next->prev = n->prev;
		free(n);
		p->quantidade--;
	}
}					

void retiraFim( lista *p) {
	struct node *n = p->sentinela->prev;
	if( n != p->sentinela ) { // lista vazia
		n->next->prev = n->prev;
		n->prev->next = n->next;
		free(n);
		p->quantidade--;
	}
}

int topo(lista *p){
	return p->sentinela->next->data;
}

int inserir( lista * l, T data) {

    struct node *novo = (struct node*)malloc(sizeof(struct node));
    if(!novo)
        return 0;

    novo->data = data;

    struct node *p = l->sentinela->next;
    while( p != l->sentinela && p->data < data) {
        p = p->next;
    }
    // inserir antes de p
    novo->next = p;
    novo->prev = p->prev;
    p->prev->next = novo;
    p->prev = novo;

    l->quantidade++;
    return 1;
}