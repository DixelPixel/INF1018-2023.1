#include <stdio.h>

unsigned char switch_byte(unsigned char x);
unsigned char rotate_left(unsigned char x, int n);
int main() {
  
    printf("%x == %x \n", 0xab, switch_byte(0xab));
    printf("%x == %x left\n", 0x61, rotate_left(0x61,1));
    printf("%x == %x left\n", 0x61, rotate_left(0x61,2));
    printf("0x%x ==0x%x left\n", 0x61, rotate_left(0x61,3));

  return 0;
}

unsigned char switch_byte(unsigned char x){
    unsigned char ret1=x>>4;
    unsigned char ret2=x<<4;

    return ret1+ret2;

}
unsigned char rotate_left(unsigned char x, int n){
    return (x>>(8-n)) + (x<<n);
}