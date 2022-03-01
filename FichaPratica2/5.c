#include<stdio.h>

int MDC(int a, int b){
    if(b == 0)
        return a;
    else
        return MDC(b, a%b);
}

int main(){
    int res = MDC(36, 90);
    printf("%d", res);

    return 0;
}