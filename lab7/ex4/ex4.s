/*
#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/


.data
nums:  .int  65, -105, 111, 34
Sf:  .string "%d\n"    /* primeira string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/
  movl $0, %ebx
  movq $nums, %r12
  movl $0, %ecx

L1:
  cmpl  $4, %ebx  /* if (*pc == 0) ? */
  je  L3       /* goto L3 */
    

  movq %r12, %r13 /*r13 = r12*/  

  movl %ebx, %edx /*edx = ebx*/
  
  imull $4, %edx  /*edx = edx*4 --(sizeof int)*/  
  
  addq %rdx, %r13  
  
  addl (%r13), %ecx  /*ecx = *r13*/

  addl $1, %ebx

  jmp L1

/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
/*************************************************************/
L3:
  movl %ecx, %eax  

  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */  

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/
