/*
João Pedro Biscaia Fernandes - 2110361
João Gabriel Cunha - 2211302
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "arv.h"

int boo(No * no);
int max(int x, int y){
  return x >= y ? x:y;
}

int main(void) {
  // tópico a, gerar os números aleatórios e exibir as chaves na ordem gerada.
  int num, count=0;
  srand(time(NULL));
  int nums[10];
  
  printf("----------------------------------------\n");
  printf("Números gerados, em ordem:\n");
  while(count<10){
    int found = 0;
    num = rand() % 20 +1;
    for(int j = 0; j < count; j++ ){
      if(nums[j]==num){
        found = 1;
        break;
      }
    }
    if(found==0){
      nums[count] = num;
      count++;
    }
  }
  for(int i =0;i<10;i++){
    printf("%d\n", nums[i]);
  }
  printf("----------------------------------------\n");
  /*Árvore ABB*/
  No * abb = cria_lista();
  No * a_nivel = cria_lista();
  for(int i = 0;i < 10; i++){
    abb = insere_ABB(abb, nums[i]);
    a_nivel = insere_nivel(a_nivel, nums[i]);
  }
  printf("----------------------------------------\n");
  printf("Árvore ABB em pré ordem:\n");
  printf("----------------------------------------\n");
  printf("Percurso de pré ordem:\n");
  pre(abb);
  printf("----------------------------------------\n");
  printf("Árvore em nível em pré ordem:\n");
  printf("----------------------------------------\n");
  printf("Percurso de pré ordem:\n");
  pre(a_nivel);
  
  printf("----------------------------------------\n");
  verifica_ABB(abb);
  printf("----------------------------------------\n");
  verifica_ABB(a_nivel);
  printf("----------------------------------------\n");


  printf("Calculando altura das árvores:\n");
  printf("Altura abb = %d\n",altura(abb));
  printf("Altura a_nivel = %d\n",altura(a_nivel));

  printf("\nInvertendo Árvores\n\n");
  troca_nos(abb);
  troca_nos(a_nivel);
  printf("Árvore ABB invertida:\n");
  printf("----------------------------------------\n");
  printf("Percurso de pré ordem:\n");
  pre(abb);
  printf("----------------------------------------\n");
  printf("Árvore em nível invertida:\n");
  printf("----------------------------------------\n");
  printf("Percurso de pré ordem:\n");
  pre(a_nivel);
  printf("----------------------------------------\n");  

  printf ("FINALMENTE = %d\n\n", boo(abb));



  
  return 0;
}

void pre(No * p) {
  /*Percorre a lista no percurso pré ordem usando recursão. Primeiro acessa o nó pai, printando o mesmo. Depois o nó esquerdo, printando-o se não estiver vazio, e por fim printa o direito, se não estiver vazio.*/
  if(p==NULL){
    printf("Árvore vazia!\n");
    return;
  }
  visita(p);
  if (p->left != NULL){
    pre(p->left);
  }
  if (p->right != NULL)
   pre(p->right);
}

void visita(No * p){
  if(p!=NULL){
    printf("Chave = %d  / Nó = %p / Nó esquerdo = %p  / Nó direito = %p\n",p->key, p, p->left, p-> right);
    return;
  }
}
No * cria_lista(){
  return NULL;
}
No * insere_ABB(No * no, int key){
  /* Função para inserção em ABB. Procura o próximo nó null passando por uma comparação. Se a chave for menor que a da chave do nó atual, passa pelo esquerdo; caso contrário, passa para o direito se for maior. Caso seja igual, só retorna o endereço do nó. No final, se estiver em um nó null, insere na árvore. */
  if(no==NULL){
    return cria_no(key);
  }
  else if(key < no->key){
    no->left =  insere_ABB(no->left,key);
  }
  else if(key > no->key){
    no->right = insere_ABB(no->right,key);
  }
  return no;

  
}

No * cria_no(int key){
  No * novo_no = (No*)malloc(sizeof(No));
  if(novo_no==NULL){
    printf("Erro na alocação de memória.\n");
    return NULL;
  }
  novo_no->key = key;
  novo_no->left = NULL;
  novo_no->right = NULL;
  return novo_no;
}
void verifica_ABB(No * no){
  /*Função iterativa que verifica se uma árvore é ABB. Procura por todos os nós através de uma fila auxiliar, se a chave do nó atual for menor que a do nó esquerdo ou maior que o nó direito, significa que não é abb, quebrando o loop e retornando.*/
  if(no==NULL){
    printf("Árvore vazia!\n");
    return;
  }
  Fila * fila = cria_fila();
  fila = push_fila(no, fila);
  while(fila!=NULL){
    if(fila->no->left!=NULL){
      if(fila->no->key <= fila->no->left->key ){
      printf("Árvore com raiz %p e chave %d não é ABB! Nó pai = %d / Nó filho esquerdo = %d\n", no, no->key, fila->no->key, fila->no->left->key);
      return;
      }
      fila = push_fila(fila->no->left, fila);
    }
    else if(fila->no->right!=NULL){
      if(fila->no->key >= fila->no->right->key){
        printf("Árvore não é ABB! Nó pai = %d // Nó filho direito = %d\n", fila->no->key, fila->no->left->key);
        return;
      }
      fila = push_fila(fila->no->right, fila);
      
    }
    fila = pop(fila);
  }
  printf("Árvore com raiz %p e chave %d é ABB\n", no, no->key);

  
}

No * insere_nivel(No * lst, int key){
  if(lst == NULL){
    return cria_no(key);
  }
  /*Esse algoritmo faz uma fila onde sempre será observado o primeiro nó, ou seja, o primeiro nó que tenha nós esquerdo ou direito vazios. Se um deles estiver, insere na árvore e quebra o loop. Senão, insere o esquerdo que será o primeiro a ser visualizado na fila, pois é a prioridade na inserção de nível, e depois o direito, onde a iteração passará para o próximo inserido.*/
  Fila * fila = cria_fila();
  fila = push_fila(lst, fila);
  while(fila!=NULL){
    if(fila->no->left==NULL){
      fila->no->left = cria_no(key);
      break;
    }
    else if(fila->no->right==NULL){
      fila->no->right = cria_no(key);
      break;
    }
    fila = push_fila(fila->no->left, fila);
    fila = push_fila(fila->no->right, fila);
    fila = pop(fila);
  }

  return lst;
  
}

Fila * push_fila(No * no, Fila * lst){
  /*Função iterativa para inserir elemento em fila. Procura o próximo nó null, pega o ponteiro que aponta para ele e faz apontar para um novo elemento. O novo elemento aponta para null. */
  Fila * novo_val = (Fila*) malloc(sizeof(Fila));
  if(novo_val==NULL){
    printf("Falha ao alocar memória, retornando NULL");
    return NULL;
  }
  novo_val->no = no;
  novo_val->prox=NULL;
  if(lst==NULL){
    return novo_val;
  }
  Fila * aux = lst;
  Fila * ant = NULL;
  while(aux->prox!=NULL){
    ant = aux;
    aux = aux->prox;
  }
  if(ant==NULL){
    lst->prox = novo_val;
    return lst;
  }
  aux->prox = novo_val;
  return lst;
}
Fila*  pop(Fila * fila){
  if(!fila){
    printf("Lista vazia\n");
    return NULL;
  }
  fila = fila->prox;
  return fila;
}
Fila * cria_fila(){
  return NULL;
}
void troca_nos(No*no){
  /*Função recursiva que altera todos os nós esquerdos pelos direitos em uma árvore binária*/
  if(no == NULL){
    return;
  }
  No * aux = no->left;
  no->left = no->right;
  no->right = aux;

  troca_nos(no->left);
  troca_nos(no->right);

}
int altura(No* no){
  /*Função recursiva que retorna altura de uma árvore binária. Compara alturas do caminho esquerdo com direito, retornando o maior dos 2.*/
  if(no==NULL){
    return 0;
  }
  int h_max = 0;
  int h_left = 0;
  int h_right = 0;

  if(no->left!=NULL){
    h_left = 1 + altura(no->left);
  }
  if(no->right!=NULL){
    h_right = 1 + altura(no->right);
  }
  return h_left > h_right ? h_left : h_right;
}