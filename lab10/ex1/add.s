/*
int add (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}
*/
.globl add

.text

add:
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %ebx /*  a=0  */
    movq %rdi, %r12

for:
    cmpq $0, %r12
    je end

    addl (%r12), %ebx

    movq 8(%r12), %r12
    jmp for

end:
    movl %ebx, %eax
    leave 
    ret
