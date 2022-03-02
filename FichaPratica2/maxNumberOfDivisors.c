#include<stdio.h>

// Terminal
int maxDivisors(int n, int i, int res){
    if(i==n+1)
        return res;
    else{
        if(n % i == 0){
            printf("%d ", i);
            maxDivisors(n, i+1, res+1);
        }
        else
            maxDivisors(n, i+1, res);
    }
}

int main(){
    int res = maxDivisors(100, 1, 0);
    printf("\nResultado: %d\n", res);

    return 0;
}