#include <stdio.h>
#include <stdlib.h>


int main (void) {
  int line = 1;
  int  c;
  FILE *f;
  funcp funcaoSimples;
  unsigned char codigo[6];
  
  int res;
    /* Abre o arquivo fonte */
  if ((f = fopen("programa", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função Simples */
  funcaoSimples = gera(f, codigo);
  fclose(f);

  /* chama a função */
  res = (*funcaoSimples);
  printf("res = %02x\n",res);




  return 0;
}

