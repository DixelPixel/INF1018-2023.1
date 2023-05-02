#include <stdio.h>
#include <stdlib.h>
#include "trab1.h"
#include "trab1.c"


int main(void){
    // testes:
    //soma:
    //caso 1: a> 0 && b> 0 
    BigInt a,b,res;
    unsigned long long a1,b1;
    a1 = ((long long)0xffffffeeadedffff);
    b1 = ((long long)5);
    big_val(a,a1);
    big_val(b,b1);
    big_mul(res,a,b);
    long long ab = a1*b1;
    printf("Resposta esperada: = %02llx\n", ab);
    printf("Resposta encontrada: = ");
    for(int i =15; i>=0;i--){
        printf("%02x",res[i]);
    }
    printf("\n");


    return 0;
}