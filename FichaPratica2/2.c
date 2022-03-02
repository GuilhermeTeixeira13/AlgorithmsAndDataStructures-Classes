#include<stdio.h>
#include<string.h>


int contaCaracteres(char palavra[], int inicio){
    if(palavra[inicio] == '\0')
        return 0;
    else
        return 1 + contaCaracteres(palavra, inicio+1);
}

int contaCaracteresTerminal(char palavra[], int inicio, int res){
    if(palavra[inicio] == '\0')
        return res;
    else
        return contaCaracteresTerminal(palavra, inicio+1, res+1);
}

int main(){
    char palavra[] = "Joao";

    int res = contaCaracteres(palavra, 0);
    printf("Normal: %d\n", res);

    int resTerm = contaCaracteresTerminal(palavra, 0, 0);
    printf("Terminal: %d\n", resTerm);

    return 0;
}