#include<stdio.h>
#include <math.h>

int DoisElevadoA(int n){
    if(n == 0)
        return 1;
    else
        return 2 * DoisElevadoA(n-1);
}

int main(){

    int res = DoisElevadoA(4);
    printf("%d", res);
    return 0;
}