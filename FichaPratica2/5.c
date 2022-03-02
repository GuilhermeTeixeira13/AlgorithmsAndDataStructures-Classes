#include<stdio.h>

int MDC(int a, int b){
    if(b == 0)
        return a;
    else
        return MDC(b, a%b);
}

int MDCterminal(int a, int b, int res){
    if(b == 0)
        return res;
    else
        return MDCterminal(b, a%b, b);
}

int main(){
    int res = MDC(36, 90);
    printf("Normal: %d\n", res);

    int resTerm = MDCterminal(36, 90, 0);
    printf("Terminal: %d\n", resTerm);


    return 0;
}