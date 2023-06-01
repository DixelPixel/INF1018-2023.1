
.data
Sf: .string "%d" 
S2: .string "numero: "


.globl novonum
 

.text
novonum:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movq $S2, %rdi
    movl $0, %eax
    call printf

    movq $Sf, %rdi
    leaq -4(%rbp), %rsi
    call scanf

    movl -4(%rbp), %eax

    leave
    ret

