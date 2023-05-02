#include <stdio.h>


void foo(int a[], int n);

int main(void){
    int a[5]= {5,4,0,3,2};

    foo(a, sizeof(a)/4);

    for(int i = 0;i<5;i++){
        printf("%d\n", a[i]);
    }

    return 0;
}