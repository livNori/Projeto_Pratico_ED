#ifndef LISTA_H
#define LISTA_H

typedef int T;											//

struct node {												//
  T data;
  struct node *next, *prev;
};

typedef struct {										//
  struct node *sentinela;
  unsigned quantidade;							
} lista;														

void inicializa(lista *p);					//
void destuir(lista *p);							//
void limpar(lista *p);
int vazia(lista *p);								//
int cheia(lista *p);								//
unsigned tamanho(lista *p);					//
void insere(lista *p, T item);			//
void retira(lista *p);							//
void retiraFim(lista *p);						//
int topo(lista *p);				//
int inserir( lista * l, T data);


#endif