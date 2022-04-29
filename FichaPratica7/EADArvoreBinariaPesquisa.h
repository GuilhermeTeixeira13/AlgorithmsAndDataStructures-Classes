
// Operações sobre ABP cuja chave é o campo "NFatura"

int pesquisarABP (INFOAB X, PNodoAB T){   // 0 = nao existe; 1 = existe
  if (T == NULL)
    return 0;
  if (compararElementosAB(X, T->Elemento) == 0)   // X == T->Elemento
    return 1;
  if (compararElementosAB(X, T->Elemento) == -1)  // X < T->Elemento
    return pesquisarABP(X, T->Esquerda);
  else
    return pesquisarABP(X, T->Direita);
}

PNodoAB inserirABP (INFOAB X, PNodoAB T){
  if (T == NULL){
    T = criarNodoAB(X);
    return T;
  }
  if (compararElementosAB(X, T->Elemento) == -1)  // X < T->Elemento
    T->Esquerda = inserirABP(X, T->Esquerda);
  else
    T->Direita = inserirABP(X, T->Direita);
  return T;
}


PNodoAB substituirNodoDireita (PNodoAB T, INFOAB *X){
  PNodoAB  PAux;
  if (T->Esquerda == NULL){
    *X = T->Elemento;
    PAux = T;
    T = T->Direita;
    PAux = libertarNodoAB(PAux);
    return T;
  }
  T->Esquerda = substituirNodoDireita(T->Esquerda, X);
  return T;
}

PNodoAB substituirNodoEsquerda (PNodoAB T, INFOAB *X){
  PNodoAB  PAux;
  if (T->Direita == NULL){
    *X = T->Elemento;
    PAux = T;
    T = T->Esquerda;
    PAux = libertarNodoAB(PAux);
    return T;
  }
  T->Direita = substituirNodoEsquerda(T->Direita, X);
  return T;
}

PNodoAB removerNodoABP (PNodoAB T){
  PNodoAB R;
  INFOAB X;
  if (T->Esquerda == NULL && T->Direita == NULL){   // T é uma folha
    T = libertarNodoAB(T);
    return T;
  }
  if (T->Esquerda == NULL){    //  só um filho, o direito 
    R = T;
    T = T->Direita;
    R = libertarNodoAB(R);
    return T;
  }
  if (T->Direita == NULL){    // só um filho, o esquerdo
    R = T;
    T = T->Esquerda;
    R = libertarNodoAB(R);
    return T;
  }
  // 2 filhos (1º caso): remover o nodo sucessor (nodo mais à esquerda da subárvore direita) e copiar a sua informação
  T->Direita = substituirNodoDireita(T->Direita, &X);
  // 2 filhos (2º caso): remover o nodo antecessor (nodo mais à direita da subárvore esquerda) e copiar a sua informação
  //  T->Esquerda = substituirNodoEsquerda(T->Esquerda, &X);	// 2º caso
  T->Elemento = X;
  return T;
}

PNodoAB removerABP (INFOAB X, PNodoAB T){
  if (compararElementosAB(X, T->Elemento) == 0){
    T = removerNodoABP(T);
    return T;
  }		
  if (compararElementosAB(X, T->Elemento) == -1)
    T->Esquerda = removerABP(X, T->Esquerda);
  else
    T->Direita = removerABP(X, T->Direita);
  return T;
}