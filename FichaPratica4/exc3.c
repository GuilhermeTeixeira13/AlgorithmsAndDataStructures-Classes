#include <stdio.h>
#include <stdlib.h>
#include "Aleatorio.h"
#include "ListasLigadasSimples.h"

int main(){
  int num = 0;
  int a;
  PNodo Lista = criarLista();

  pritnf("Digite um número inteiro: ");
  scanf("%d", &num);

  while(a>0){
    num = num / 10;
    a = num % 10;
    
  }




  return 0;
}