#include <stdio.h>
#include <stdlib.h>
#include "trab1.h"

// int main(void) {
//   BigInt res,a,b;
//   big_val(a,0x7fffffffffffffff);
//   big_val(b,0xfffffffffffff0ff);
//   printf("a = ");
//   for(int i =15; i>=0;i--){
//     printf("%02x",a[i]);
//   }
//   printf("\nb = ");
//   for(int i =15; i>=0;i--){
//     printf("%02x",b[i]);
//   }
//   big_sub(res,a,b);
//   printf("\nres = ");
//   for(int i =15; i>=0;i--){
//     printf("%02x",res[i]);
//   }
//   printf("\n");
//   return 0;
// }

void big_val (BigInt res, long val){
  for(int i =0; i<8;i++){
    res[i]=(unsigned char)((val>>i*8));
  }
  for(int i = 8;i<16;i++){
    if((val&0x8000000000000000)==0x8000000000000000){
      unsigned char val = 0xff;
      res[i]=val;
    }
    else{
       res[i]=0; 
    }
  }
  
  
}
void big_sar(BigInt res, BigInt a, int n){
  unsigned char over=0;
  for(int el=0;el<16;el++){
          res[el]=a[el];
  }
  for(int cont=0;cont<n; cont++){
          for(int el=15;el>=0;el--){
                  unsigned char element = (unsigned char)res[el];
                  res[el] = (element/2)+over;
                  over = element*128;
                  if((el==15) && ((element/128)==1)){
                          res[el]+=0x80;
                  }
          }
          over=0;
  }
  return;
}
void big_shr(BigInt res, BigInt a, int n){
        unsigned char over=0;
        for(int el=0;el<16;el++){
                res[el]=a[el];
                printf("%x\n", res[el]);
        }
        for(int cont=0;cont<n; cont++){
                for(int el=15;el>=0;el--){
                        unsigned char element = (unsigned char)res[el];
                        printf("el = %d\n",el);
                        res[el] = (element>>1)+over;
                        over = element<<7;
                        if((el==15) && (element&0x80)){
                                res[el]+=0x80;
                        }
                }
                over=0;
        }
        return;
}

void big_shl(BigInt res, BigInt a, int n){
    unsigned char over=0;
    for(int el=0;el<16;el++){
        res[el]=a[el];
        printf("%x\n", res[el]);
    }
    for(int cont=0;cont<n;cont++){
        for(int el=0;el<16;el++){
            unsigned char element = (unsigned char)res[el];
            res[el]= (element<<1)+over;
            over = element>>7;
        }
        over=0;
    }
    return;
}

void big_comp2(BigInt res, BigInt a){
  char prox =1;
  if((a[15]& 0x80) ==0x80){
    for(int i = 0;i<16;i++){
        res[i] = ~a[i]+prox; 
        if(res[i]!=0){
          prox = 0;
        }
    }
  }
  else{
    for(int i = 0;i<16;i++){
        res[i] = ~a[i]+prox; 
        if(res[i]!=0){
          prox = 0;
        }
    }
  }
}

void big_sum (BigInt res, BigInt a, BigInt b){
  char resto = 0;
  //casos de soma com positivos:
  if(((a[15]& 0x80) == 0x00)&&((b[15] & 0x80) == 0x00)){
    for(int i = 0;i<16;i++){
      res[i]= a[i]+b[i]+resto;
      if(a[i]>=0x7f||b[i]>=0x7f){
        resto = 1;
      }
      else{
        resto = 0;
      }
    }
    return;
  }
  // caso de soma com a e b negativos:
  else if(((a[15]& 0x80) == 0x80)&&((b[15] & 0x80) == 0x80)){
    big_comp2(a,a);
    big_comp2(b,b);
    for(int i = 0;i<16;i++){
      res[i]= a[i]+b[i]+resto;
      if(a[i]>=0x7f||b[i]>=0x7f){
        resto = 1;
      }
      else{
        resto = 0;
      }
    }
    big_comp2(res,res);
    return;
  }
  //a < 0 e b>0: res = b - a
  else if((a[15]&0x80)==0x80){
    big_sub(res,b,a);
    return;
  }
  //a>0 e b<0: res = a - b
  else{
    big_sub(res,a,b);
    return;
  }

}

void big_sub (BigInt res, BigInt a, BigInt b){
  //convertendo b para negativo ou positivo:
  // a > 0 && b < 0 : a - (-b) = a+b  || a<0 && b > 0: -a - (-b) = -(a+b)
  if((((a[15]& 0x80) == 0x00)&&((b[15] & 0x80) == 0x80))||(((a[15]& 0x80) == 0x80)&&((b[15] & 0x80) == 0x00))){
    big_comp2(b,b);
    big_sum(res,a,b);
    return;
  }
  else{
    big_comp2(b,b);
    char resto = 0;
    for(int i = 0;i<16;i++){
      if(b[i]>a[i]){
        res[i] = (b[i]+a[i]-resto);
        resto = 1;
      }
      else{
        res[i] = (a[i]+b[i]-resto);
        resto = 0;
      }

    }
    printf("\n");
    return;
  }
}