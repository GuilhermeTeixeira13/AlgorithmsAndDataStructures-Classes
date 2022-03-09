#include<stdio.h>
#include<stdlib.h>

struct Nodo {
  INFO   Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;


PNodo criarLista (){
  PNodo L;
  L = NULL;
  return L;
}

PNodo criarNodo (INFO X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

void libertarNodo (PNodo P){ 
  free(P);
  P = NULL;
}

int listaVazia (PNodo L){
  if (L == NULL)
    return 1;
  else
    return 0;
}


void mostrarListaInicio (PNodo L){
  PNodo P = L;
  while (P != NULL){
    mostrarElemento(P->Elemento);
    P = P->Prox;
  }
  printf("\n\n");
}

void mostrarListaInicioRec (PNodo L){
  if (L != NULL){
    mostrarElemento(L->Elemento);
    mostrarListaInicioRec(L->Prox);
  }
}

void mostrarListaFimRec (PNodo L){
  if (L != NULL){
    mostrarListaFimRec(L->Prox);
    mostrarElemento(L->Elemento);
  }
}

int tamanhoLista (PNodo L){
  int  tam = 0; 
  while (L != NULL){
    tam++;
    L = L->Prox;
  } 
  return tam;
}

int tamanhoListaRec (PNodo L){ 
  if (L == NULL) 
    return 0; 
  else 
    return 1 + tamanhoListaRec(L->Prox);
}

int pesquisarLista (INFO X, PNodo L){ 
  while (L != NULL && compararElementos(L->Elemento, X) != 0)
    L = L->Prox;
  if (L == NULL)
    return 0;
  else
    return 1;
} 

int pesquisarListaRec (INFO X, PNodo L){
  if (L == NULL) 
    return  0;
  if (compararElementos(L->Elemento, X) == 0) 
    return  1; 
  else 
    return pesquisarListaRec(X, L->Prox);
}

PNodo procurarAntecessor (INFO X, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && compararElementos(L->Elemento, X) != 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

PNodo procurarAntecessorRec (INFO X, PNodo L){ 
  if (compararElementos(L->Elemento, X) == 0) 
    return  NULL;   //  só acontece se X estiver no início de L 
  if (compararElementos(L->Prox->Elemento, X) == 0) 
    return  L; 
  return procurarAntecessorRec(X, L->Prox);
}

PNodo inserirListaInicio (INFO X, PNodo L){
  PNodo P;
  P = criarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

PNodo inserirListaFim (INFO X, PNodo L){ 
  PNodo P, PAux;
  P = criarNodo(X); 
  if (P == NULL) 
    return L; 
  if (L == NULL) 
    return P;
  PAux = L; 
  while (PAux->Prox != NULL)    // marcar o elemento do fim de L
    PAux = PAux->Prox;
  PAux->Prox = P; 
  return  L; 
}

PNodo inserirListaFimRec (INFO X, PNodo L){
  PNodo P; 
  if (L == NULL){      // só acontece se a lista inicial for vazia
    P = criarNodo(X); 
    if (P != NULL)
      L = P; 
    return  L;
  } 
  if (L->Prox == NULL){      // fim da lista L
    P = criarNodo(X); 
    if (P != NULL)
      L->Prox = P;
  } 
  else 
    inserirListaFimRec(X, L->Prox);    // o que devolve não interessa 
  return L;    // devolve o início da lista 
}

// assume-se que a lista está ordenada por ordem crescente
PNodo procurarAntecessorOrdem (INFO X, PNodo L){ 
  PNodo Ant = NULL; 
  while (L != NULL && compararElementos(L->Elemento, X) < 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant; 
} 

PNodo inserirListaOrdem (INFO X, PNodo L){
  PNodo P, PAnt;
  P = criarNodo(X); 
  if (P == NULL) 
    return  L; 
  if (L == NULL) 
    return  P;    // a lista L inicia-se em P
  PAnt = procurarAntecessorOrdem(X, L); 
  if (PAnt == NULL){   // inserir no início de L
    P->Prox = L; 
    return  P;
  }   
  P->Prox = PAnt->Prox;
  PAnt->Prox = P;
  return  L; 
}

// remover X da lista L, em que X está na lista
PNodo removerLista (INFO X, PNodo L){ 
  PNodo P, PAnt;
  PAnt = procurarAntecessor(X, L); 
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->Prox;
  } 
  else{
    P = PAnt->Prox;
    PAnt->Prox = P->Prox; // ou (PAnt->Prox)->Prox
  } 
  libertarNodo(P); 
  return  L;
}

// remover X da lista L, em que X está na lista
PNodo removerListaRec (INFO X, PNodo L, PNodo LAux) {
  PNodo  P;
  if (compararElementos(L->Elemento, X) == 0){   // X está no início da Lista L
    P = L;
    L = L->Prox;
    libertarNodo(P);
    return  L;
  }
  if (compararElementos(LAux->Prox->Elemento, X) == 0){    
    // X está na lista L, mas não no inicio
    P = LAux->Prox;
    LAux->Prox = P->Prox;    // ou LAux->Prox->Prox;
    libertarNodo(P);
    return L;
  }
  return removerListaRec(X, L, LAux->Prox);
}

