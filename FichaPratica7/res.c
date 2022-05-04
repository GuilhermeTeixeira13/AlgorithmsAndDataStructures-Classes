#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"
#include "EADArvoreBinariaPesquisa.h"
#include "ABPorNiveis.h"

// Ex. A.1
PNodoAB construirABPAleatoria(int N)
{
  PNodoAB T;
  T = criarAB();
  for (int i = 0; i < N; i++)
  {
    INFOAB elArv = criarElementoAB();
    T = inserirABP(elArv, T);
  }
  return T;
}

// Ex. A.2
int numeroElementosABEsquerda(PNodoAB T)
{
  return numeroNodosAB(T->Esquerda);
}

int numeroElementosABDireita(PNodoAB T)
{
  return numeroNodosAB(T->Direita);
}

int alturaArbB(PNodoAB T)
{
  return alturaAB(T);
}

// Ex. A.3
PNodoAB maiorvalorNFatura(PNodoAB T)
{
  if (T == NULL)
  {
    return NULL;
  }
  if (T->Direita == NULL)
  {
    return T;
  }

  return maiorvalorNFatura(T->Direita);
}

// Ex. A.4
PNodoAB menorvalorNFatura(PNodoAB T)
{
  if (T == NULL)
  {
    return NULL;
  }
  if (T->Esquerda == NULL)
  {
    return T;
  }

  return menorvalorNFatura(T->Esquerda);
}

// Ex. A.5
int numElementosMaioresA(PNodoAB T, int A)
{
  int dir, esq;

  if (ABVazia(T))
  {
    return 0;
  }

  dir = numElementosMaioresA(T->Direita, A);
  esq = numElementosMaioresA(T->Esquerda, A);

  if (T->Elemento.NFatura > A)
  {
    return esq + dir + 1;
  }
  else
  {
    return esq + dir;
  }
}

/*
6. Implementar uma função uma função que dada uma ABP T e um valor inteiro A, devolva o
nodo associado ao elemento com valor do campo NFatura igual a A, se existir; se não existir,
deve devolve NULL.
*/
// Ex. A.6
PNodoAB nodoNFaturaigualA(PNodoAB T, int A)
{
  PNodoAB esq, dir;

  if (ABVazia(T->Direita) && ABVazia(T->Esquerda) && (T->Elemento.NFatura == A))
  {
    return T;
  }

  if (T->Direita != NULL)
  {
    dir = nodoNFaturaigualA(T->Direita, A);
  }
  if (T->Esquerda != NULL)
  {
    esq = nodoNFaturaigualA(T->Esquerda, A);
  }

  if (T->Direita != NULL && dir->Elemento.NFatura == A)
  {
    return dir;
  }
  if (T->Esquerda != NULL && esq->Elemento.NFatura == A)
  {
    return esq;
  }

  return NULL;
}

// Ex. A.9
PNodoAB removerElemento(INFOAB X, PNodoAB arvore)
{
  if (pesquisarABP(X, arvore) == 1)
    return removerABP(X, arvore);
  else
    return arvore;
}

// Ex. A.10
int ordenaEmVetor(PNodoAB arvore, int *v, int pos)
{
  if (arvore == NULL)
    return pos;

  if (arvore->Esquerda != NULL)
    pos = ordenaEmVetor(arvore->Esquerda, v, pos);

  v[pos] = arvore->Elemento.NFatura;
  pos++;

  if (arvore->Direita != NULL)
    pos = ordenaEmVetor(arvore->Direita, v, pos);

  return pos;
}

// Ex. A.5
int nivelMaiorMenor(PNodoAB T)
{
  int dir, esq;

  if (ABVazia(T))
  {
    return 0;
  }

  dir = nivelMaiorMenor(T->Direita);
  esq = nivelMaiorMenor(T->Esquerda);

  if (T->Direita == NULL && T->Esquerda == NULL)
  {
    return esq + dir + 1;
  }
  else
  {
    return esq + dir;
  }
}

int main(void)
{
  PNodoAB T;
  int N;

  // Ex 1
  N = gerarNumeroInteiro(0, 15); // numero de nodos da ABP
  T = construirABPAleatoria(N);
  printf("Ex 1 -  Construir uma árvore binária T com N elementos de tamanho: %d\n\n", N);
  mostrarEmOrdemAB(T);

  printf("\n\n\n");

  // Ex 3
  printf("Ex 3 - Determine o nodo de T com maior valor da chave (campo NFatura)\n\n");
  PNodoAB maiorNFatura;
  maiorNFatura = maiorvalorNFatura(T);
  mostrarElementoAB(maiorNFatura->Elemento);

  printf("\n\n\n");

  // Ex 4
  printf("Ex 4 - Determine o nodo de T com menor valor da chave (campo NFatura)\n\n");
  PNodoAB menorNFatura;
  menorNFatura = menorvalorNFatura(T);
  mostrarElementoAB(menorNFatura->Elemento);

  printf("\n\n\n");

  // Ex 5
  int A = 1600;
  int res_5;
  printf("Ex 5 - Determine o número de elementos de T cujos valores do campo NFatura são superiores a %d\n\n", A);
  res_5 = numElementosMaioresA(T, A);
  printf("NºElementos com o campo chave(NFatura) maior que %d: %d\n\n", A, res_5);

  printf("\n\n\n");

  // Ex 6
  /*int A1 = 1638;
  PNodoAB nodoigualA;
  printf("Ex 6 - Nodo associado ao elemento com valor do campo NFatura igual a %d, se existir; se não existir, deve devolver NULL\n\n", A1);
  nodoigualA = nodoNFaturaigualA(T, A1);
  printf("Nodo com o campo chave(NFatura) igual a %d:\n", A1);
  mostrarElementoAB(nodoigualA->Elemento);
  printf("\n\n\n");*/

  // Ex 9
  printf("Ex 9 - Árvore sem o elemento %d\n\n", (T->Direita)->Elemento.NFatura);
  T = removerElemento((T->Direita)->Elemento, T);
  mostrarEmOrdemAB(T);

  // Ex 10
  int *vetor = (int *)malloc(numeroNodosAB(T) * sizeof(int));
  ordenaEmVetor(T, vetor, 0);
  for (int i = 0; i < numeroNodosAB(T); i++)
  {
    printf("|%d", vetor[i]);
  }

  printf("\n\n");
  mostrarPorNiveis(T);

  return 0;
}