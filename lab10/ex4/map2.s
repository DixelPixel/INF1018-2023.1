/*
int f(int x);

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}
*/


.globl map2

.text

map2:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    movq %rdi, -8(%rbp)
    movq %rsi, -16(%rbp)
    movl %edx, -20(%rbp)
    movq $0, %rdi
    movq $0, %rsi
    movl $0, %edx


    movl $0, %ebx   /* i = 0 */

for:
    cmpl -20(%rbp), %ebx
    je end

    movq -8(%rbp), %r12
    movq -16(%rbp), %r13

    movl %ebx, %r14d
    imull $4, %r14d

    addq %r14, %r12
    addq %r14, %r13

    movl (%r12), %edi

    call f 

    movl %eax, (%r13)
    addl $1, %ebx
    
    jmp for

end:
    movq -8(%rbp), %rdi
    movq -16(%rbp), %rsi
    movl -20(%rbp), %edx  
    addq $32, %rsp
    leave
    ret
    