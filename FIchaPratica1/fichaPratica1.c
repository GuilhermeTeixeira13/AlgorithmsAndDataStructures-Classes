#include<stdio.h>
#include<stdlib.h>

typedef struct ALUNO {
  int numAluno; // Número de aluno
  int Notas[4]; // Notas em Aprendizagem, Ex. Normal, Ex. Recurso e Ex. Especial
  int NotaFinal; // melhor nota das 4 anteriores
} ALUNO;


int maiorVetor (int V[], int N){
  int maior = V[0];

  for(int i=1; i<N; i++){
    if(V[i] > maior){
      maior = V[i];
    }
  }

  return maior;
}

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

ALUNO *lerVetor (int *N){
  FILE *f = abreFicheiro("Alunos.txt", "r");

  ALUNO *a;
  a = (ALUNO *) malloc (*N * sizeof(ALUNO));

  int x = 0;
  int *i;
  i=&x;

  while ((fscanf(f, "%d %d %d %d %d\n", &a[*i].numAluno, &a[*i].Notas[0], &a[*i].Notas[1], &a[*i].Notas[2], &a[*i].Notas[3])) == 5 && *i < *N){
    a[*i].NotaFinal = maiorVetor(a[*i].Notas, 4);
    x++;
  }
  
  fechaFicheiro(f, "Alunos.txt");

  return a;
}

void gravaTXT(ALUNO *alunos, char *fnome, int *N)
{
    FILE *f = abreFicheiro(fnome, "w");

    for (int i = 0; i < *N; i++)
        fprintf(f, "%d %d %d %d %d %d\n", alunos[i].numAluno, alunos[i].Notas[0], alunos[i].Notas[1], alunos[i].Notas[2], alunos[i].Notas[3], alunos[i].NotaFinal);
    fechaFicheiro(f, fnome);
}

int determinaMelhorAluno(ALUNO *alunos, int *N){
  int numAlunoMelhorNota = alunos[0].numAluno;
  int melhorNotaFinal = alunos[0].NotaFinal;
  for(int i=0; i<*N; i++){
    if(alunos[i].NotaFinal>melhorNotaFinal){
      melhorNotaFinal = alunos[i].NotaFinal;
      numAlunoMelhorNota = alunos[i].numAluno;
    }
  }
  return numAlunoMelhorNota;
}

int main(){
  int numLinhas;
  numLinhas = contaLinhas("Alunos.txt");
  int *numLinhasApontador;
  numLinhasApontador=&numLinhas;

  ALUNO *alunos;
  alunos = lerVetor(numLinhasApontador);

  //ALUNO aluno1;
  //aluno1 = lerVetor(numLinhasApontador)[1];

  for(int i=0; i<*numLinhasApontador; i++){
    printf("Num.ALuno:%d, Nota1:%d, Nota2:%d, Nota3:%d, Nota4:%d, NotaFinal:%d\n", alunos[i].numAluno, alunos[i].Notas[0], alunos[i].Notas[1], alunos[i].Notas[2], alunos[i].Notas[3], alunos[i].NotaFinal);
  }

  gravaTXT(alunos, "AlunosFinal.txt", numLinhasApontador);

  printf("O melhor aluno é o %d.\n", determinaMelhorAluno(alunos, numLinhasApontador));

  return 0;
}