#include<stdio.h>
#include<string.h>


int contaCaracteres(char palavra[], int inicio, int fim){
    if(palavra[inicio] == '\0')
        return 0;
    else
        return 1 + contaCaracteres(palavra, inicio+1, fim);
}

int contaCaracteresTerminal(char palavra[], int inicio, int fim, int res){
    if(palavra[inicio] == '\0')
        return res;
    else
        return contaCaracteresTerminal(palavra, inicio+1, fim, res+1);
}

int main(){
    char palavra[] = "Palavra";

    int res = contaCaracteres(palavra, 0, strlen(palavra)-1);
    printf("Normal: %d\n", res);

    int resTerm = contaCaracteresTerminal(palavra, 0, strlen(palavra)-1, 0);
    printf("Terminal: %d\n", resTerm);

    return 0;
}