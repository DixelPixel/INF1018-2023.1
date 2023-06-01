/*
João Pedro Biscaia Fernandes 2110361 3WB
Felipe barcellos 2110710 3WB
*/

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"


void big_copy (BigInt res, BigInt a){	
  /*Função simples que copia um Bigint a no BigInt res.*/															
	for(int i=0;i<(NUM_BITS/8);i++){
		res[i] = a[i];
	}
	return;
}

void big_val (BigInt res, long val){
  /*O maior valor possível passado por um long só terá 8 bytes. logo, podemos colocar todos os dígitos usando um bitshift para a esquerda com o index do for.
  Após esse for, simplesmente vemos se o número é negativo. Encontramos isso fazendo a comparação com 0x8000000000000000, que determina se o número é negativo
  Isso ocorre pois o número é simplesmente  10000....0 , pegamos esse '1' no final que representa o sinal. Se for negativo, colocamos 0xff nos bytes restantes,
  se for positivo, preenchemos com 0.
  */
  for(int i =0; i<(NUM_BITS/8)/2;i++){
    res[i]=(unsigned char)((val>>i*((NUM_BITS/8)/2)));
  }
  for(int i = 8;i<(NUM_BITS/8);i++){
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
  for(int el=0;el<16;el++){
    res[el]=a[el]; // copia a para res
  }
  for(int cont=0;cont<n; cont++){ //for que roda até o número de shifts
    unsigned over = 0;  //inicializa a variável de overflow, que no inicio é = 0
    for(int el=15;el>=0;el--){ // for que faz a operação de shift char por char começando pelo valor mais significativo
      unsigned char element = (unsigned char)res[el];  // inicializa a variavel element, já que para fazer as próximas duas linhas de código o res[el] perderia o valor
      res[el] = (element>>1)+over; //  dou um shift e somo com o over do valor anterior
      over = element<<7; // pego o overflow para a direita dando 7 shifts para a esquerda
      if((el==15) && (element&0x80)){ //se o elemento for o mais significativo e começar com 1, que dizer que ele é negativo
        res[el]+=0x80; // completo com o negativo
      }
    }
  }
  return;
}
void big_shr(BigInt res, BigInt a, int n){
        for(int el=0;el<16;el++){
          res[el]=a[el]; //copia a para res
        }
        for(int cont=0;cont<n; cont++){  //for que roda até o número de shifts
          unsigned char over=0; //inicializa a variável de overflow, que no inicio é = 0
          for(int el=15;el>=0;el--){ //for que faz a operação de shift char por char começando pelo valor mais significativo
            unsigned char element = (unsigned char)res[el]; // inicializa a variavel element, já que para fazer as próximas duas linhas de código o res[el] perderia o valor
            res[el] = (element>>1)+over; //  dou um shift e somo com o over do valor anterior
            over = element<<7; //pego o overflow para a direita dando 7 shifts para a esquerda
          }
        }
        return;
}
void big_shl(BigInt res, BigInt a, int n){
    for(int el=0;el<16;el++){
      res[el]=a[el]; // copia a para res
    }
    for(int cont=0;cont<n;cont++){ //for que roda até a quantidade de shifts n
      unsigned char over=0; // inicializa a variável over que pega o overflow de cada byte
      for(int el=0;el<16;el++){ // for que faz o shift char por char
        unsigned char element = res[el]; // inicializa element já que para as próximas linhas o res[el] perderia o valor 
        res[el]= (element<<1)+over; // shifta element para a esquerda e soma com o overflow e atribui ao res[el]
        over = element>>7; // pega o overflow desse byte
      }
    }
    return;
}

void big_comp2(BigInt res, BigInt a){
  /*A função passa por todos os bytes, fazendo complemento a 2 e somando 1 no começo até ser a soma resultar em um char > 0, que significa que não passou
  um resto para a próxima casa.
  */

  char prox =1;
  for(int i = 0;i<16;i++){
      res[i] = ~a[i]+prox; 
      if(res[i]!=0){
        prox = 0;
      }
  }
  
  
}

void big_sum (BigInt res, BigInt a, BigInt b){
  /*O algoritmo funciona da mesma maneira que funciona o algoritmo normal da soma. Soma-se byte por byte, passando o resto da soma para o próximo byte.*/
  char resto = 0;  //variável que mede o "overflow" da soma
  //casos de soma com positivos:
  big_val(res,0); 
  for(int i = 0;i<(NUM_BITS/8);i++){
    unsigned int over = a[i]+b[i]+resto; //soma com possível overflow
    resto = over>>8; //tratamento de overflow
    res[i]= over;
  }
}

void big_sub (BigInt res, BigInt a, BigInt b){
  /*Considerando que a-b = a+(-b), essa função somente inverte o sinal de b e faz a soma. Para não alterar nenhum valor, foram criados BigInts auxiliares.*/
  BigInt a1,b1;
  big_copy(a1,a);
  big_copy(b1,b);
  big_comp2(b1,b1);
  big_sum(res,a1,b1);
}

void big_mul (BigInt res, BigInt a, BigInt b){
  /*O algoritmo usado é o mesmo de multiplicação, onde multiplica-se todos os bytes de a pelo primeiro de b, colocando o resultado no resultante.
  Depois, passa para o segundo byte de b sendo multiplicado por todos de a, somando com o resultado atual do vetor resultante, e passando o resto da soma(vai um)
  para a soma do próximo byte, assim continuando até os bytes de b terminarem. Logo, foi feito 2 loops, um para todos os bytes de b, e um dentro deste, para que para cada byte de b, multiplique por todos os de A,
  assim como o algoritmo explicado. Além disso, o significado de utilizar res[i+j] é para representar a passagem de casas no algoritmo de multiplicação.
  */
  BigInt a1,b1;
  big_copy(a1,a);
  big_copy(b1,b);

  long n = 0;
  big_val(res,n);
  for (int i = 0; i < (NUM_BITS/8); i++) {//for para cada byte de b
    unsigned int over = 0; //overflow da soma de cada multiplicação do byte de b pelo byte em a.
    for (int j = 0; j < (NUM_BITS/8) - i; j++) {//for para pegar cada byte em a em cada multiplicação por cada byte de b
        int tmp= a1[j]*b1[i]+ over+ res[i+j]; //soma com possível overflow
        over= tmp>>8; //tratamento de overflow
        res[i+j]= tmp;
    }
  }

}