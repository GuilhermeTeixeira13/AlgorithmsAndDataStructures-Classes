#include<stdio.h>
#include <math.h>

int DoisElevadoA(int n){
    if(n == 0)
        return 1;
    else
        return 2 * DoisElevadoA(n-1);
}

int DoisElevadoATerminal(int n, int res){
    if(n == 0)
        return res;
    else
        return DoisElevadoATerminal(n-1, res*2);
}

int main(){

    int res = DoisElevadoA(4);
    printf("Normal: %d\n", res);

    int resTerm = DoisElevadoATerminal(4, 1);
    printf("Terminal: %d\n", resTerm);

    return 0;
}