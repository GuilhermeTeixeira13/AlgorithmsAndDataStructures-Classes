#include<stdio.h>

typedef struct{
  int   NFatura;
  int   NIF;
  int   Data[3];
  float Pagamento;
}INFOP;


void mostrarElemento (INFOP X){
  printf("%d - ", X.NFatura);
  printf("%d - ", X.NIF);
  printf("%2d/%2d/%4d - ", X.Data[0], X.Data[1], X.Data[2]);
  printf("%f\n",  X.Pagamento);
}

INFOP criarElemento (){
  INFOP X;
  X.NFatura = gerarNumeroInteiro(1000, 2000);
  X.NIF = gerarNumeroInteiro(100780, 100790);
  X.Data[2] = gerarNumeroInteiro(2010, 2022);
	X.Data[1] = gerarNumeroInteiro(1, 12);
	if(X.Data[1] == 2)
		  X.Data[0] = gerarNumeroInteiro(1, 28);
	else
	  if (X.Data[1] == 4 || X.Data[1] == 6 || X.Data[1] == 9 || X.Data[1] == 11)
		  X.Data[0] = gerarNumeroInteiro(1, 30);
		else
		  X.Data[0] = gerarNumeroInteiro(1, 31);
  X.Pagamento = gerarNumeroReal(10.0, 1000.0);
  return X;
}

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementos (INFOP X, INFOP Y){
  if (X.NFatura > Y.NFatura)
    return 1;
  if (X.NFatura < Y.NFatura)
    return -1;
  return 0;
}