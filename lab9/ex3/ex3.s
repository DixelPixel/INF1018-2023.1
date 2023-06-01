/*
void foo (int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}
*/

.globl foo

.text
foo:
  pushq %rbp
  movq %rsp, %rbp

  subq $16, %rsp
  movl %ebx, -4(%rbp)
  movl %ecx, -8(%rbp)

  movl $0, %ebx   /* i = 0*/
  movl $0, %ecx  /* s = 0 // como não chamo função, não tem problema usar o registrador que seria o quarto parâmetro.*/
  
  movq %rdi, %r12


Loop:

  cmpl %esi, %ebx
  je L1

  movq %r12, %r13
  movl %ebx, %edx
  imull $4, %edx
  addq %rdx, %r13
  addl (%r13), %ecx
  addl $1, %ebx

  cmpl $0, (%r13)
  jne Cont

  movl %ecx, (%r13)
  movl $0, %ecx

Cont: 
  jmp Loop

L1:
  movl -4(%rbp), %ebx
  movl -8(%rbp), %ecx
  addq $16, %rsp
  leave
  ret
  
