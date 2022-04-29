typedef PNodoAB INFOF;

struct NodoFila{
  INFOF  Elemento;
  struct NodoFila *Prox;
};
typedef struct NodoFila *PNodoFila;

// Operações sobre o Nodo

PNodoFila criarNodoFila (INFOF X){
  PNodoFila P;
  P = (PNodoFila) malloc(sizeof(struct NodoFila));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodoFila libertarNodoFila (PNodoFila P){ 
  P->Prox = NULL;
  free(P);
  P = NULL;
  return P;
}

// Operações sobre a Pilha

PNodoFila criarFila (){
  PNodoFila P;
  P = NULL;
  return P;
}

int filaVazia (PNodoFila Q){
  if (Q == NULL)
    return 1;
  else
    return 0;
}

PNodoFila juntar (INFOF X, PNodoFila Q){
  PNodoFila Novo, PAnt;
  Novo = criarNodoFila(X);
  if (Novo == NULL)
    return Q;
  if (filaVazia(Q)){
    Q = Novo;
    return Q;
  }
  PAnt = Q;
  while(PAnt->Prox != NULL)
    PAnt = PAnt->Prox;
  PAnt->Prox = Novo;
  return Q;
}


PNodoFila remover (PNodoFila Q){
  PNodoFila P;
  P = Q;
  Q = Q->Prox;
  P = libertarNodoFila(P);
  return Q;
}


PNodoAB frente (PNodoFila Q){
  return Q->Elemento;
}