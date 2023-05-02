.globl add2

.text

add2:
    pushq %rbp
    movq %rsp, %rbp

    subq $16, %rsp

    cmpq $0, %rdi
    jne rec
    movl $0, %eax
    jmp fim

rec:
    movl (%rdi), %ebx
    movl %ebx, -8(%rbp)
    movq 8(%rdi),%rdi
    call add2
    movl -8(%rbp), %r12d
    addl %eax, %r12d
    movl %r12d, %eax

fim:
    movl -8(%rbp), %ebx
    addq $16, %rsp
    leave 
    ret
