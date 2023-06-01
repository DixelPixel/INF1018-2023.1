.globl vai
.text

vai:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp
    movl %ebx, -16(%rbp)
    movl %r12d, -20(%rbp)

    movl $0, %ebx
    movl $0, %r12d
    movq %rsi, -8(%rbp)
    movl %edi, -12(%rbp)
    movq $0, %rsi


for:
    cmpl -12(%rbp), %ebx
    je end
    
    /*indexação do array*/
    movq -8(%rbp), %r13
    movl %ebx, %r14d
    imull $8, %r14d
    addq %r14, %r13
    /*******************/
    
    movl (%r13), %edi
    call ebom

    movl %eax, %r12d
    cmpl $0, %r12d
    ja cont
    movl $0, 4(%r13)
    jmp iter
cont:
    movl %r12d, 4(%r13)

iter:
    addl $1, %ebx
    jmp for

end:
    movl -16(%rbp), %ebx
    movl -20(%rbp), %r12d
    addq $32, %rsp
    leave 
    ret
