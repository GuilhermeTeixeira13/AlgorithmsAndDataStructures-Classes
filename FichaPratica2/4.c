#include<stdio.h>

int fib(int n){
    if(n < 2)
        return n;
    else
        return fib(n-1)+fib(n-2);
}

int fibTerminal(int n, int a, int b){
    if(n == 0)
        return a;
    if(n == 1)
        return b;
    else
        return fibTerminal(n-1, b, a+b);
}

int main(){
    printf("Normal: ");
    for(int i=0; i<10; i++){
        int res = fib(i);
        printf("%d-", res);
    }
    printf("\nTerminal: ");
    for(int i=0; i<10; i++){
        int resTerm = fibTerminal(i, 0, 1);
        printf("%d-", resTerm);
    }
    printf("\n");
    return 0;
}