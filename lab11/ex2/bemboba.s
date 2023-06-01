
.globl bemboba

.text
bemboba:
    pushq %rbp
    movq %rsp, %rbp

    subq $48, %rsp

    movq %rbx, -8(%rbp)
    movq %r12, -16(%rbp)
    movq %rdi, -24(%rbp)
    movq %r13, -32(%rbp)

    movl $0, %ebx

    movl -24(%rbp), %r12d
    leaq -40(%rbp), %r13


for:
    cmpl $4, %ebx
    je add

    movl %r12d, (%r13)

    addl $1, %ebx
    addq $4, %r13

    jmp for


add:
    leaq -40(%rbp), %rdi
    movl $4, %esi

    call addl

    movq -8(%rbp), %rbx
    movq -16(%rbp), %r12
    movq -24(%rbp), %rdi
     movq -32(%rbp), %r13

    leave 
    ret
