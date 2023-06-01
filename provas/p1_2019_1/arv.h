struct no{
  int key;
  struct no* left;
  struct no* right;
};
typedef struct no No;

struct fila{
  No * no;
  struct fila * prox;
};
typedef struct fila Fila;


/*Percorre a lista no percurso pré ordem usando recursão. Primeiro acessa o nó pai, printando o mesmo. Depois o nó esquerdo, printando-o se não estiver vazio, e por fim printa o direito, se não estiver vazio.*/
void pre(No * p);

/*Printa o nó se não estiver vazio*/
void visita(No * p);

/*retorna null.*/
No * cria_lista();

/*faz alocação de memória de nó de acordo com uma chave.*/
No * cria_no(int key);

/* Função iterativa para inserção em ABB. Procura o próximo nó null passando por uma comparação. Se a chave for menor que a da chave do nó atual, passa pelo esquerdo; caso contrário, passa para o direito se for maior. Caso seja igual, só retorna o endereço do nó. No final, se estiver em um nó null, insere na árvore. */
No * insere_ABB(No * lst, int key);

/*Esse algoritmo faz uma fila onde sempre será observado o primeiro nó, ou seja, o primeiro nó que tenha nós esquerdo ou direito vazios. Se um deles estiver, insere na árvore e quebra o loop. Senão, insere o esquerdo que será o primeiro a ser visualizado na fila, pois é a prioridade na inserção de nível, e depois o direito, onde a iteração passará para o próximo inserido.*/
No * insere_nivel(No * lst, int key);

/*Função iterativa que verifica se uma árvore é ABB. Procura por todos os nós através de uma fila auxiliar, se a chave do nó atual for menor que a do nó esquerdo ou maior que o nó direito, significa que não é abb, quebrando o loop e retornando.*/
void verifica_ABB(No * no);

/*Função recursiva que altera todos os nós esquerdos pelos direitos em uma árvore binária*/
void troca_nos(No*no);

/*Função recursiva que retorna altura de uma árvore binária. Compara alturas do caminho esquerdo com direito, retornando o maior dos 2.*/
int altura(No* no);

/*retorna null*/
Fila * cria_fila();

/*Função iterativa para inserir elemento em fila. Procura o próximo nó null, pega o ponteiro que aponta para ele e faz apontar para um novo elemento. O novo elemento aponta para null. */
Fila * push_fila(No * no, Fila * lst);

/*remove primeiro item da fila.*/
Fila*  pop(Fila * fila);