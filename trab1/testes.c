#include <stdio.h>
#include <stdlib.h>
#include "trab1.h"
#include "trab1.c"


int main(void){
    // testes:
    //soma:
    //caso 1: a> 0 && b> 0 
    BigInt a,b,c,res;
    big_val(a,0x0ffffffffffffff5);
    big_val(b,0x0ffffffffffffff7);
    big_sub(res,a,b);
    printf("\nres = ");
    for(int i =15; i>=0;i--){
        printf("%02x",res[i]);
    }



    return 0;
}