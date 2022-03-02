#include<stdio.h>
#include<stdlib.h>

/*   ↓  Abre o ficheiro 'fnome' no modo 'modo'  ↓   */
FILE *abreFicheiro(char *fnome, char *modo) 
{
    FILE *f = fopen(fnome, modo);

    if (f == NULL)
    {
        fprintf(stderr, "Falhou abertura de %s.\n", fnome);
        exit(EXIT_FAILURE);
    }

    return f;
}

/*   ↓  Fecha o ficheiro 'f' que se chama 'fnome'  ↓   */
void fechaFicheiro(FILE *f, char *fnome)
{
    if (fclose(f) == EOF)
    {
        fprintf(stderr, "Falhou o fecho de %s.\n", fnome);
        exit(EXIT_FAILURE);
    }
}

int contaLinhas(char *fnome) {
  FILE *f = abreFicheiro(fnome, "r");

  char c;
  int count = 0;

  for (c = getc(f); c != EOF; c = getc(f)){
    if (c == '\n') // Increment count if this character is newline
      count = count + 1;
  }

  fechaFicheiro(f, fnome);

  return count+1;
}

float *lerVetor (int *N){
  FILE *f = abreFicheiro("ReaisPositivos.txt", "r");

  float *arrayInt;
  arrayInt = (float *) malloc (*N * sizeof(float));

  int i = 0;

  while ((fscanf(f, "%f\n", &arrayInt[i]) == 1 && i < *N)){
    i++;
  }
  
  fechaFicheiro(f, "ReaisPositivos.txt");

  return arrayInt;
}

int main(){
  int numLinhas;
  numLinhas = contaLinhas("ReaisPositivos.txt");
  int *numLinhasApontador;
  numLinhasApontador=&numLinhas;

  float *arrayInt;
  arrayInt = lerVetor(numLinhasApontador);

  for(int i=0; i<*numLinhasApontador; i++){
    printf("%f\n", arrayInt[i]);
  }

  return 0;
}