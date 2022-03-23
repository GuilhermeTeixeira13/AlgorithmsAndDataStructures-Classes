#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "ListasLigadasSimples.h"

typedef struct {
  int a;
  Nodo *prox;
} Nodo;

typedef struct {
  Nodo *head;
  int n; // tamanho
}Lista;

int main(){
  int num = 0;
  int alg;
  Nodo *no;
  Nodo *noAux;
  Lista L;

  printf("Digite um número inteiro: ");
  scanf("%d", &num);

  while(num!=0){
    num = num / 10;
    alg = num % 10;
    no = (Nodo *) malloc(sizeof(Nodo));
    no->a = alg;
    no->prox = NULL;
    if(L.n == 0){
      L.head = &no;
      L.n++;
    }
    noAux->prox = no;
    noAux = no;
  }
  

  return 0;
}