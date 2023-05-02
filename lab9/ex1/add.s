
.globl add
.text
  
    add:
        movl %edi, %eax
        addl %esi, %eax
        addl %edx, %eax
ret
