#include<stdio.h>
#include<stdbool.h>

int primoTerminal(int n, int divisor){
    if(divisor == 1)
      return true;
    else{
      if(n % divisor == 0)
        return false;
      else
        return primoTerminal(n, divisor-1);
    }
}

int main(){
    int res = primoTerminal(17, 16);
    if(res==1)
      printf("É primo.");
    else
      printf("Não é primo.");

    return 0;
}