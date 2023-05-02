/*

struct X {
  int val1;
  int val2;
};

int f(int i, int v);

void boo (struct X *px, int n, int val) {
  while (n--) {
    px->val2 = f(px->val1, val);
    px++;
  }
}

*/

.text
.globl boo
boo:
    pushq %rbp
    movq %rsp, %rbp

    movq %rdi, %rbx
    subq $16, %rsp   /*alocando para a pilha*/

    movq %rdi, -8(%rbp)
    movl %esi, -12(%rbp)
    movl %edx, -16(%rbp)
    movq $0, %rdx
    movq -8(%rbp), %r12

while:
    cmpl $0, -16(%rbp)
    je L2
    movl (%r12), %edi
    movl -16(%rbp), %esi
    
    call f

    movl %eax, 4(%r12)
    addq $8, %r12
    subl $1, -16(%rbp)

    jmp while

L2:

    leave 
    ret




