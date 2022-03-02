#include<stdio.h>

int MDCTerminal(int a, int b){
    if(b == 0)
        return a;
    else
        return MDCTerminal(b, a%b);
}

int main(){
    int res = MDCTerminal(36, 90);
    printf("Terminal: %d\n", res);

    return 0;
}