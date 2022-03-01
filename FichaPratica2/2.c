#include<stdio.h>
#include<string.h>


int contaCaracteres(char palavra[], int inicio, int fim){
    if(palavra[inicio] == '\0')
        return 0;
    else
        return 1 + contaCaracteres(palavra, inicio+1, fim);
}

int main(){
    char palavra[] = "Palavra";
    int res = contaCaracteres(palavra, 0, strlen(palavra)-1);
    printf("%d", res);

    return 0;
}