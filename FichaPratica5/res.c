#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasP.h"
#include "EADPilha.h"

void mostrarPilha (PNodoPilha S){
  PNodoPilha P = S;
  printf("TOPO\n");
  while (P != NULL){
    mostrarElemento(P->Elemento);
    P = P->Ant;
  }
  printf("CAUDA\n");
}

// .1
PNodoPilha criarPilhaAleatoria (int N){
  PNodoPilha pilha;
  pilha = criarPilha();

  for(int i=0; i<N; i++){
    INFOP inf = criarElemento();
    pilha = push(inf, pilha);
  }

  return pilha;
}

// .2 - Altera a pilha
INFOP funcao2 (PNodoPilha Pilha){
  Pilha = pop(Pilha);

  return Pilha->Elemento;
}

// .3 - Não altera a pilha
INFOP funcao3 (PNodoPilha Pilha){
  int pos = 0;

  while (Pilha != NULL){
    if(pos == 1)
      return topo(Pilha);
    Pilha = Pilha->Ant;
    pos++;
  }
}


int main(){
  PNodoPilha Pilha;
  PNodoPilha Pilha1;
  int N;
  
  // .1
  N = gerarNumeroInteiro(8, 15);
  Pilha = criarPilhaAleatoria(N);
  Pilha1 = Pilha;
  mostrarPilha(Pilha);

  //.2 - Altera a pilha
  /*printf("\n\nEXC2\nO segundo elemento da pilha é: ");
  mostrarElemento(funcao2(Pilha));
  printf("\nA pilha ficou assim:\n");
  mostrarPilha(Pilha);*/

  //.3 - Não altera a pilha
  printf("\n\nEXC3\nO segundo elemento da pilha é: ");
  mostrarElemento(funcao3(Pilha1));
  printf("\nA pilha ficou assim:\n");
  mostrarPilha(Pilha1);

  return 0;
}