.text
.globl boo

boo:
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %ebx
    movl $0, %r12d
    subq $16, %rsp

    movq %rdi, -8(%rbp)

    cmpq $0, %rdi
    jne rec
    
    movl $0, %eax
    jmp end

rec:
    movq -8(%rbp), %r13
    movq 8(%r13), %rdi

    call boo

    movl %eax, -12(%rbp)
    movq -8(%rbp), %r13
    movq 16(%r13), %rdi

    call boo

    movl %eax, -16(%rbp)
    movl -12(%rbp), %edi
    movl -16(%rbp), %esi

    call max 

    addl $1, %eax


end:
    movq -8(%rbp), %rdi
    addq $16, %rsp
    leave 
    ret
