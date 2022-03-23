#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "OperacoesPrimarias.h"
#include "ListasLigadasSimples.h"

// 1.
PNodo criarListaAleatoria (int N){
  PNodo Lista;
  Lista = criarLista();

  for(int i=0; i<N; i++){
    INFO inf = criarElemento();
    Lista = inserirListaFim(inf, Lista);
  }

  return Lista;
}

// Ficha - 1
float maiorPagamento(PNodo L, int ano){
  float maiorPagamento = 0;

  while(listaVazia(L) != 1){
    if(L->Elemento.Data[2] == ano && L->Elemento.Pagamento > maiorPagamento){
      maiorPagamento = L->Elemento.Pagamento;
    }
    L = L->Prox;
  }

  return maiorPagamento;
}

// 3.
float funcao3Rec (PNodo L, int num){
  if(listaVazia(L) == 1)
    return 0;
  else{
    if(L->Elemento.NIF == num)
      return L->Elemento.Pagamento + funcao3Rec(L->Prox, num);
    else
      return funcao3Rec(L->Prox, num);
  }
}
float funcao3Iterativa (PNodo L, int num){
  float sum=0;
  while(listaVazia(L) != 1){
    if(L->Elemento.NIF == num)
      sum += L->Elemento.Pagamento;
    L = L->Prox;
  }
  return sum;
}


// 4.
int funcao4Rec (PNodo L, float pag){
  if(listaVazia(L) == 1)
    return 0;
  else{
    if(L->Elemento.Pagamento >= pag)
      return 1 + funcao4Rec(L->Prox, pag);
    else
      return funcao4Rec(L->Prox, pag);
  }
}
int funcao4Iterativa (PNodo L, float pag){
  int qntd=0;
  while(listaVazia(L) != 1){
    if(L->Elemento.Pagamento >= pag)
      qntd += 1;
    L = L->Prox;
  }

  return qntd;
}


// 5.
float funcao5Iterativa(PNodo L){
  float maior = L->Elemento.Pagamento;
  L = L->Prox;
  while(listaVazia(L) != 1){
    if(L->Elemento.Pagamento >= maior)
      maior = L->Elemento.Pagamento;
    L = L->Prox;
  }

  return maior;
}
float funcao5Rec(PNodo L, float maior){
  if(listaVazia(L) == 1)
    return maior;
  else{
    if(L->Elemento.Pagamento >= maior)
      return funcao5Rec(L->Prox, L->Elemento.Pagamento);
    else
      return funcao5Rec(L->Prox, maior);
  }
}

// 6.
INFO funcao6Iterativa(PNodo L, float k){

  INFO menorElemento = {.NFatura=0, .NIF=0, .Data[0]=0, .Data[1]=0, .Data[2]=0, .Pagamento=0};
  while(listaVazia(L) != 1){
    if(L->Elemento.Pagamento >= k)
      menorElemento = L->Elemento;
    L = L->Prox;
  }

  return menorElemento;
}

// 7.
PNodo funcao7Iterativa(PNodo L, int num){
  while(listaVazia(L) != 1){
    if(L->Elemento.NFatura == num)
      return removerLista(L->Elemento, L);
    L = L->Prox;
  }
}

// 8.
PNodo funcao8(PNodo L){
  float maior = funcao5Iterativa(L);

  PNodo temp = L, prev;

  // If head node itself holds the key or multiple
  // occurrences of key
  while (temp != NULL && temp->Elemento.Pagamento < maior)
  {
    L = temp->Prox; // Changed head
    free(temp); // free old head
    temp = L; // Change Temp
  }

  while (temp != NULL)
  {
    // Search for the key to be deleted, keep track of
    // the previous node as we need to change
    // 'prev->next'
    while (temp != NULL && temp->Elemento.Pagamento >= maior)
    {
      prev = temp;
      temp = temp->Prox;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
      return L;
 
    // Unlink the node from linked list
    prev->Prox = temp->Prox;
 
    free(temp); // Free memory
 
    // Update Temp for next iteration of outer loop
    temp = prev->Prox;
  }
  return L;
}

int main(){
  PNodo Lista;
  int tamLista;
  
  tamLista = gerarNumeroInteiro(15, 20);
  printf("\n\nTamanho da lista\nN = %d\n\n", tamLista);

  // 1.
  Lista = criarListaAleatoria(tamLista);

  // 2.
  printf("EXC 2\nDo início para o fim:\n");
  mostrarListaInicioRec(Lista);
  printf("\n\nDo fim para o início:\n");
  mostrarListaFimRec(Lista);

  // Ficha - 1
  printf("----------------------------------------------------------\n");
  PNodo ListaFicha = criarListaAleatoria(15);
  mostrarListaFimRec(ListaFicha);
  int A = (ListaFicha->Prox)->Elemento.Data[2];
  float maiorPag = maiorPagamento(ListaFicha, A);
  printf("\nMaior pagamento do ano %d: %f\n", A, maiorPag);
  printf("----------------------------------------------------------");

  // 3.
  int NIFaAnalisar = 100783;
  float somaPagosRec = funcao3Rec(Lista, NIFaAnalisar);
  float somaPagosIT = funcao3Iterativa( Lista, NIFaAnalisar);
  printf("\nEXC 3\n[REC] Soma dos pagamentos das faturas que contêm o NIF %d: %f$\n", NIFaAnalisar ,somaPagosRec);
  printf("[ITER] Soma dos pagamentos das faturas que contêm o NIF %d: %f$\n", NIFaAnalisar ,somaPagosIT);


  // 4.
  float valorPag = 500;
  int qntElemRec = funcao4Rec(Lista, valorPag);
  int qntElemIt = funcao4Iterativa(Lista, valorPag);
  printf("\n\nEXC 4\n[REC] Quantidade de elementos com pagamento >= %f: %d elementos\n", valorPag, qntElemRec);
  printf("[ITER] Quantidade de elementos com pagamento >= %f: %d elementos\n", valorPag, qntElemIt);

  // 5.
  float maiorIT = funcao5Iterativa(Lista);
  float maiorREC = funcao5Rec(Lista, 0);
  printf("\n\nEXC 5\n[ITERATIVA] O maior pagamento da lista é --> %f\n", maiorIT);
  printf("[RECURSIVA] O maior pagamento da lista é --> %f\n", maiorREC);

  // 6.
  INFO menorElIT = funcao6Iterativa(Lista, 200);
  printf("\n\nEXC 6\n[ITERATIVA] O elemento é -->\n");
  mostrarElemento(menorElIT);

  // 7.
  printf("\n\nEXC 7\nPrimeiro elemento:\n");
  mostrarElemento(Lista->Elemento);
  Lista = funcao7Iterativa(Lista, Lista->Elemento.NFatura);
  printf("\nLista sem o primeiro elemento\n\n");
  mostrarListaInicio(Lista);

  // 8.
  printf("\n\nEXC 8\nLista sem valores cujo pagamento é menor que o maior pagamento da lista:\n\nMaior pagamento:%f\n\nLista Nova:\n", funcao5Iterativa(Lista));
  mostrarListaInicio(funcao8(Lista));

  return 0;
}