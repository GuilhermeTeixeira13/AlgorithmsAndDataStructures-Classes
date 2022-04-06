#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimariasAB.h"
#include "EADArvoreBinaria.h"

#define max(a, b) \
  ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

// EXC 1
PNodoAB criarABAleatoria(int N)
{
  INFOAB cont;
  PNodoAB arvore;

  arvore = criarAB();

  for (int k = 0; k < N; k++)
  {
    cont = criarElementoAB();
    arvore = inserirPorAlturaAB(cont, arvore);
  }

  return arvore;
}

// EXC3
void numNodosEsqDir(PNodoAB arvore, int *esq, int *dir)
{
  *dir = numeroNodosAB(arvore->Direita);
  *esq = numeroNodosAB(arvore->Esquerda);
}

// EXC 4
int numElementosNIFigualK(PNodoAB arvore, int k)
{
  int esq, dir;
  if (ABVazia(arvore))
    return 0;

  esq = numElementosNIFigualK(arvore->Esquerda, k);
  dir = numElementosNIFigualK(arvore->Direita, k);

  // printf("|%d|%d|\n", esq, dir);
  if (arvore->Elemento.NIF == k)
    return 1 + esq + dir;
  else
    return esq + dir;
}

// EXC 5
INFOAB ElementoMaiorAno(PNodoAB arvore)
{
  INFOAB esq, dir, maior;

  // Condição de paragem
  if (arvore->Esquerda == NULL && arvore->Direita == NULL)
    return arvore->Elemento;

  // Chamadas recursivas que enchem uma stack
  if (arvore->Esquerda != NULL)
    esq = ElementoMaiorAno(arvore->Esquerda);
  if (arvore->Direita != NULL)
    dir = ElementoMaiorAno(arvore->Direita);

  // A stack é percorrida e daí tira-se o maior
  maior = arvore->Elemento;
  if (arvore->Esquerda != NULL && esq.Data[2] > maior.Data[2])
    maior = esq;
  if (arvore->Direita != NULL && dir.Data[2] > maior.Data[2])
    maior = dir;

  return maior;
}

int main()
{
  PNodoAB arvore;
  int N;

  // EXC 1
  N = gerarNumeroInteiro(1, 15);
  arvore = criarABAleatoria(N);
  printf("Mostrar árvore  de %d elementos criada no EXC 1:\n", N);
  printf("\nEm ordem:\n");
  mostrarEmOrdemAB(arvore);
  printf("\nPré-ordem:\n");
  mostrarPreOrdemAB(arvore);
  printf("\nEm ordem:\n");
  mostrarPosOrdemAB(arvore);

  // EXC 3
  int numElementosSubArvEsq = 0, numElementosSubArvDir = 0;
  numNodosEsqDir(arvore, &numElementosSubArvEsq, &numElementosSubArvDir);
  printf("\nA subarvore esquerda tem %d elementos.\nA subarvore direita tem %d elementos.\n", numElementosSubArvEsq, numElementosSubArvDir);

  // EXC 4
  int NIFprimeiroElemento = arvore->Elemento.NIF;
  int numElementosIgualNIF = numElementosNIFigualK(arvore, NIFprimeiroElemento);
  printf("\nHá %d elementos com o NIF igual a %d.", numElementosIgualNIF, NIFprimeiroElemento);

  // EXC 5
  int maiorAnoDaArv = ElementoMaiorAno(arvore).Data[2];
  printf("\nO maior ano presente na árvore é: %d", maiorAnoDaArv);

  return 0;
}