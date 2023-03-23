#include <stdio.h>

int odd_ones(unsigned int x);
int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  /* o byte menos significativo de x e os outros bits em 0 */
  y = x&0x000000ff;

  /* o byte mais significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
  z = x|0xff000000;
    printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
    printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");

}




int odd_ones(unsigned int x){
	int par=0;
	for(int i=0;i<32;i++){
		par += (x>>i)& 0x00000001; 
	}
    if(par&0x00000001){
        return 1;
    }
    else{
        return 0;
    }
}