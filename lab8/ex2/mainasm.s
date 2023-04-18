  .data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string "%d\n"

  .text
  .globl main
  main:
  /* prologo */
     pushq %rbp
     movq  %rsp, %rbp
     subq  $16, %rsp
     movq  %rbx, -8(%rbp)
     movq  %r12, -16(%rbp)

  /* coloque seu codigo aqui */
    movq $nums, %r12
    movl $0, %r13d

  L1:
    cmpl $5, %r13d
    je L2

    movl (%r12), %eax

    movl %eax, %edi
    movl $1, %esi
    call filtro

    movq    $s1, %rdi    /* primeiro parametro (ponteiro)*/
    movl    %eax, %esi  /* segundo parametro  (inteiro) */
    movl $0, %eax
    call  printf       /* chama a funcao da biblioteca */

    addq $4, %r12
    addl $1, %r13d
    jmp L1


  L2:


  /* finalizacao */
     movq -8(%rbp), %rbx
     movq -16(%rbp), %r12
     leave
     ret
