#include<stdio.h>

int contaDigitos(int n){
    if(n / 10 == 0)
        return 1;
    else
        return 1+contaDigitos(n/10);
}

int main(){
    int res = contaDigitos(12345);
    printf("%d", res);
    return 0;
}