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


  return 0;
}