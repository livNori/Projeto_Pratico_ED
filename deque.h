#ifndef __DEQUE__
#define __DEQUE__

#define DEQUE_MAX 550000

// Tipos de Estruturas
typedef struct TDeque
{
  int numeros[DEQUE_MAX];
  int inicio, fim, M;
} TDeque;
 
// Protótipo das funções
//M - tamanho máximo do deque
//x - elemento a ser inserido no deque
void inicializar(TDeque *p, int M);
void quant(TDeque *p, int M);
int vazio(TDeque *p);
int cheio(TDeque *p);
void IInicio(TDeque *p,int x);
void IFim(TDeque *p, int x);
int RInicio(TDeque *p);
int RFim(TDeque *p);
int inicio(TDeque *p);
int fim(TDeque *p);

#endif