#include <stdio.h>
#include <stdlib.h>


struct A{
    int v;
    struct A *esq;
    struct A *dir;
};

int max(int x, int y){
    return x>y ? x:y;
}


int main(void){
    struct A arv;



    return 0;
}