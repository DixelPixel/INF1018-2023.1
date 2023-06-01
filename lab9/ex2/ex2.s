/*
int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/
.globl fat

.text
fat:
  pushq %rbp
  movq %rsp, %rbp
  subq $16, %rsp
  cmpl $0, %edi
  jne L2
  movl $1, %eax
  jmp L1

L2:
  movl %edi, %ebx
  subl $1, %ebx
  movl %edi, -8(%rbp)
  movl %ebx, %edi
  call fat
  movl -8(%rbp), %r12d
  imull %eax, %r12d
  movl %r12d, %eax

L1:
  addq $16, %rsp
  leave
  ret
  