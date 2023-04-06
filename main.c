#include <stdio.h>
#include "deque.h"

//M - tamanho máximo do deque
//x - elemento a ser inserido no deque

// Declaração das funções
void inicializar(TDeque *p, int M){
  p -> fim = -1;
  p -> inicio = -1;
  p -> M = M;
}

void quant(TDeque *p, int M){
  p->M = M;
}

int vazio(TDeque *p){   //verifica se deque está vazio
  int v;
  if (p -> inicio == -1)  {    v = 1;  }
  else  {    v = 0;  }
  return v;
}

int cheio(TDeque *p){     // verifica se deque está cheio
  int c;
  if((p -> fim + 1) % p->M == p -> inicio){
    c = 1;
  } 
  else{    
    c = 0;  
  }
  return c;
}

void IInicio(TDeque *p, int x){ // insere um elemento no inicio
  if(vazio(p)){
    p -> fim = 0;
    p -> inicio = 0;
    p -> numeros[0] = x;
  }
  else{
    p -> inicio = (p -> inicio-1 + p->M) % p->M;
    p -> numeros[p->inicio] = x;
  }
}

void IFim(TDeque *p, int x){ //insere um elemento no final
  if(vazio(p)){
    p -> fim = 0;
    p -> inicio = 0;
    p -> numeros[0] = x;
  }
  else{
    p -> fim = ( p -> fim+1) % p->M;
    p -> numeros[p->fim] = x;
  }
}

int RInicio(TDeque *p){ //remove um elemento do início 
  int r;
  
  r = p -> numeros[p->inicio];
  
  if (p -> fim == p -> inicio){
    // Remoção quando há só um elemento
    inicializar(p, p->M);
  }
  else{
    p -> inicio = (p -> inicio+1) % p->M; 
  }
  
  return r;
}

int RFim(TDeque *p){  //remove um elemento do final
  int r;
  
  r = p -> numeros[p->fim];
  
  if(p -> fim == p -> inicio){
    // Remoção quando há só um elemento
    inicializar(p, p->M);
  }
  else{
    p -> fim = (p -> fim-1 + p->M) % p->M;
  }
  
  return r;
}

int inicio(TDeque *p){
  return p->numeros[p->inicio];
}

int fim(TDeque *p){
  return p->numeros[p->fim];
}