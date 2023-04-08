#include <stdio.h>
#include <stdlib.h>
#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];
/* Atribuição (com extensão) */
void big_val (BigInt res, long val);

/* Operações Aritméticas */

/* res = -a */
void big_comp2(BigInt res, BigInt a);

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b);

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b);

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b);

/* Operações de Deslocamento */

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n);

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n);

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n);

int main(void) {
  BigInt res;
  big_val(res,0xff01030405060708);
  for(int i =0;i<16;i++){
    printf("%x\n", res[i]);
  }
  
  return 0;
}

void big_val (BigInt res, long val){
  for(int i =0; i<8;i++){
    unsigned char long_val= (unsigned char)((val>>i*8));
    printf("Valor aqui = %x\n", long_val);
    res[i]=long_val;
  }
  for(int i = 8;i<16;i++){
    if(val>>63==-1){
      res[i]=0xff;
    }
    else{
       res[i]=0; 
    }
  }
  
  
}
/*if(i=8)int sinal= long_val>>7;
if(long_val) res[i]=0xff;*/