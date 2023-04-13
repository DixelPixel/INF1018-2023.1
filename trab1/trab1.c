#include <stdio.h>
#include <stdlib.h>
#include "trab1.h"

int main(void) {
  BigInt res;
  big_val(res,0xff01030405060708);
  
  
  return 0;
}

void big_val (BigInt res, long val){
  for(int i =0; i<8;i++){
    unsigned char long_val= (unsigned char)((val>>i*8));
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
