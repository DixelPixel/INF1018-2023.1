#include <stdio.h>
#include <stdlib.h>

int main(){
    char a = 0x56;
    char b = 0x35;
    char c = 0x38;
    int ai = ((a&0x0f)<<16)+((b&0x3f)<<8)+((c&0x3f)<<0);
    printf("%02x\n",ai);  

    return 0;
}