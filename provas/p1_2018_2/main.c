#include <stdio.h>
#include <stdlib.h>

int ebom(int val){
    return val;
}
struct Fam
{
    int eva;
    int del;
};

void vai(int n, struct Fam v[]);

int main(){
    struct Fam v[5];
    v[0].eva = 1;
    v[1].eva = 2;
    v[2].eva = 3;
    v[3].eva = 4;
    v[4].eva = 5;

    vai(5,v);
    for(int i =0; i<5; i++){
        printf("%d\n",v[i].del);
    }

    return 0;
}