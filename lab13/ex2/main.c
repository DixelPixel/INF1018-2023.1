#include <stdio.h>  

typedef int (*funcp) (int x);     

int main(void) {
        int add(int x){
                return x+1;
        }

        unsigned char codigo[] = {0xe8, 0x00, 0x00, 0x00, 0x00, 0xc3};
        int deslocamento = (unsigned char*)&add - &(codigo[5]);
        codigo[1] = deslocamento;
        codigo[2] = deslocamento >> 8;
        codigo[3] = deslocamento >> 16;
        codigo[4] = deslocamento >> 24;

        funcp f=(funcp)codigo;
	int i = (*f)(20);
        printf("O valor de i é %d\n", i);
	return 0;
}