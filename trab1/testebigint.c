/*
João Pedro Biscaia Fernandes 2110361 3WB
Felipe barcellos 2110710 3WB
*/

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
#include "bigint.c"

void print_val(BigInt a);


int main(void){
    // testes:
    //soma:
    printf("Testando a função de soma:\n");
    printf("Teste 1: negativo com positivo:\n");
    BigInt a,b,res, esp;
    unsigned long a1,b1;
    a1 = 0xfff36ffff45fffff;
    b1 = 0xffffff6345;
    printf("Valores testados: %02lx e %02lx\n",a1,b1);
    big_val(a,a1);
    big_val(b,b1);
    printf("Big int 1:");
    print_val(a);
    printf("Big int 2:");
    print_val(b);
    big_sum(res,a,b);
    big_val(esp, a1+b1);
    printf("Resposta esperada: = ");
    print_val(esp);
    printf("Resposta:");
    print_val(res);


    printf("\nTeste 2: positivo com positivo:\n");
    BigInt t2,w2,res_sum2, esp2;
    unsigned long l1,l2;
    l1 = 0x45fffff;
    l2 = 0xffffff6345;
    printf("Valores testados: %02lx e %02lx\n",l1,l2);
    big_val(t2,l1);
    big_val(w2,l2);
    printf("Big int 1:");
    print_val(t2);
    printf("Big int 2:");
    print_val(w2);
    big_sum(res_sum2,t2,w2);
    big_val(esp2, l1+l2);
    printf("Resposta esperada: = ");
    print_val(esp2);
    printf("Resposta:");
    print_val(res_sum2);

    printf("\nTeste 3: negativo com negativo:\n");
    BigInt a1_sum3,a2_sum3,res_sum3, esp_sum3;
    unsigned long l1_sum3,l2_sum3;
    l1_sum3 = 0xfffffffff65fff45;
    l2_sum3 = 0xff1f67fff89f1f45;
    printf("Valores testados: %02lx e %02lx\n",l1_sum3,l2_sum3);
    big_val(a1_sum3,l1_sum3);
    big_val(a2_sum3,l2_sum3);
    printf("Big int 1:");
    print_val(a1_sum3);
    printf("Big int 2:");
    print_val(a2_sum3);
    big_sum(res_sum3,a1_sum3,a2_sum3);
    big_val(esp_sum3, l1_sum3+l2_sum3);
    printf("Resposta esperada: = ");
    print_val(esp_sum3);
    printf("Resposta:");
    print_val(res_sum3);



    /*Complemento a 2:*/
    printf("------------------------------------\n");
    printf("Testando a função de complemento a 2.\n");
    BigInt c,d;
    long val1 = 0xf0f0f0f0f0f06556;
    long val2 = 0x56789806556;
    printf("Número testado = 0x%02lx -- Resultado esperado: 0x%02lx \n", val1, -1*(val1));
    big_val(c,val1);
    printf("BigInt atualmente:\n");
    print_val(c);
    printf("Efetuando operação de complemento a 2:\n");
    big_comp2(c,c);
    print_val(c);
    printf("Segundo teste, com número positivo:\n");
    big_val(d,val2);
    printf("Número testado = 0x%02lx -- Resultado esperado: 0x%02lx \n", val2, -1*(val2));
    printf("BigInt atualmente:\n");
    print_val(d);
    printf("Efetuando operação de complemento a 2:\n");
    big_comp2(d,d);
    print_val(d);
    printf("------------------------------------\n");

    /*Subtração.*/
    printf("Testando a função de subtração.\n");
    printf("Teste 1: negativo com positivo:\n");
    BigInt e,f,res2, esp_sub1;
    long val3 = 0xf0f0f0f0f0f06556;
    long val4 = 0x56789806556;

    printf("Valores testados = 0x%02lx e 0x%02lx\n", val3, val4);
    big_val(e,val3);
    big_val(f,val4);

    printf("BigInt 1\n");
    print_val(e);
    printf("BigInt 2\n");
    print_val(f);
    printf("Resposta esperada: ");
    big_val(esp_sub1,val3-val4);
    print_val(esp_sub1);
    big_sub(res2,e,f);
    printf("Resposta: ");
    print_val(res2);

    printf("\nTeste 2: positivo com positivo:\n");
    BigInt a1_sub2,b1_sub2,res_sub2, esp_sub2;
    unsigned long l1_sub2,l2_sub2;
    l1_sub2 = 0x45ff;
    l2_sub2 = 0xffffff6345;
    printf("Valores testados: %02lx e %02lx\n",l1_sub2,l2_sub2);
    big_val(a1_sub2,l1_sub2);
    big_val(b1_sub2,l2_sub2);
    printf("Big int 1:");
    print_val(a1_sub2);
    printf("Big int 2:");
    print_val(b1_sub2);
    big_sub(res_sub2,a1_sub2,b1_sub2);
    big_val(esp_sub2, l1_sub2-l2_sub2);
    printf("Resposta esperada: = ");
    print_val(esp_sub2);
    printf("Resposta:");
    print_val(res_sub2);

    printf("\nTeste 3: negativo com negativo:\n");
    BigInt a1_sub3,a2_sub3,res_sub3, esp_sub3;
    signed long l1_sub3,l2_sub3;
    l1_sub3 = 0xfffffffff65fff45;
    l2_sub3 = 0xffffffffff45ffff;
    printf("Valores testados: %02lx e %02lx\n",l1_sub3,l2_sub3);
    big_val(a1_sub3,l1_sub3);
    big_val(a2_sub3,l2_sub3);
    printf("Big int 1:");
    print_val(a1_sub3);
    printf("Big int 2:");
    print_val(a2_sub3);
    big_sub(res_sub3,a1_sub3,a2_sub3);
    big_val(esp_sub3, (l1_sub3-l2_sub3));
    printf("Resposta esperada: = ");
    print_val(esp_sub3);
    printf("Resposta:");
    print_val(res_sub3);


    printf("------------------------------------\n");

    /*Multiplicação*/

    printf("Testando a função de multiplicação:\n");
    printf("Teste 1: negativo com positivo:\n");
    BigInt a1_mul1,b1_mul1,res1_mul1, esp1_mul1;
    unsigned long l1_mul1,l2_mul1;
    l1_mul1 = 0xfff36ffff45fffff;
    l2_mul1 = 0xf63;
    printf("Valores testados: %02lx e %02lx\n",l1_mul1,l2_mul1);
    big_val(a1_mul1,l1_mul1);
    big_val(b1_mul1,l2_mul1);
    printf("Big int 1:");
    print_val(a1_mul1);
    printf("Big int 2:");
    print_val(b1_mul1);
    big_mul(res1_mul1,a1_mul1,b1_mul1);
    big_val(esp1_mul1, l1_mul1*l2_mul1);
    printf("Resposta esperada: = ");
    print_val(esp1_mul1);
    printf("Resposta:");
    print_val(res1_mul1);


    printf("\nTeste 2: positivo com positivo:\n");
    BigInt a1_mul2,b1_mul2,res_mul2, esp_mul2;
    unsigned long l1_mul2,l2_mul2;
    l1_mul2 = 0x45ff;
    l2_mul2 = 0xffffff6345;
    printf("Valores testados: %02lx e %02lx\n",l1_mul2,l2_mul2);
    big_val(a1_mul2,l1_mul2);
    big_val(b1_mul2,l2_mul2);
    printf("Big int 1:");
    print_val(a1_mul2);
    printf("Big int 2:");
    print_val(b1_mul2);
    big_mul(res_mul2,a1_mul2,b1_mul2);
    big_val(esp_mul2, l1_mul2*l2_mul2);
    printf("Resposta esperada: = ");
    print_val(esp_mul2);
    printf("Resposta:");
    print_val(res_mul2);

    printf("\nTeste 3: negativo com negativo:\n");
    BigInt a1_mul3,a2_mul3,res_mul3, esp_mul3;
    signed long l1_mul3,l2_mul3;
    l1_mul3 = 0xfffffffff65fff45;
    l2_mul3 = 0xffffffffff45ffff;
    printf("Valores testados: %02lx e %02lx\n",l1_mul3,l2_mul3);
    big_val(a1_mul3,l1_mul3);
    big_val(a2_mul3,l2_mul3);
    printf("Big int 1:");
    print_val(a1_mul3);
    printf("Big int 2:");
    print_val(a2_mul3);
    big_mul(res_mul3,a1_mul3,a2_mul3);
    big_val(esp_mul3, (l1_mul3*l2_mul3));
    printf("Resposta esperada: = ");
    print_val(esp_mul3);
    printf("Resposta:");
    print_val(res_mul3);

    printf("------------------------------------\n");

    /*big_sar, big_shr e big_shl*/

    BigInt aux;
    big_val(aux,0xffffffffffffff7f);
    BigInt baux;
    for(int cont=0; cont<128; cont+=8){
        printf("Bit shift para direita aritmético de %d bits:\n",cont);
        big_sar(baux,aux,cont);
        print_val(baux);
        printf("Bit shift para direita lógico de %d bits:\n",cont);
        big_shr(baux,aux,cont);
        print_val(baux);
        printf("Bit shift para esquerda de %d bits:\n",cont);
        big_shl(baux,aux,cont);
        print_val(baux);
    }


    return 0;
}

void print_val(BigInt a){
    for(int i =15; i>=0;i--){
        printf("%02x",a[i]);
    }
    printf("\n");
}