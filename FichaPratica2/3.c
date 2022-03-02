#include<stdio.h>

int contaDigitos(int n){
    if(n / 10 == 0)
        return 1;
    else
        return 1+contaDigitos(n/10);
}

int contaDigitosTerminal(int n, int res){
    if(n / 10 == 0)
        return res;
    else
        return contaDigitosTerminal(n/10, res+1);
}

int main(){
    int res = contaDigitos(12345);
    printf("Normal: %d\n", res);

    int resTerm = contaDigitosTerminal(12345, 1);
    printf("Terminal: %d\n", resTerm);

    return 0;
}