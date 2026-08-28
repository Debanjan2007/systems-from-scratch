#include<stdio.h>

// Copy of memcpy()
void my_memcpy(void *dst ,const void *src , size_t size){ 
    for(int i = 0 ; i < size ; i++){
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    }
}

int main(){
    int a[] = {1 , 25 , 45 , 88};
    int b[4];
    printf("Before :");
    for(int i = 0 ; i < 4 ; i++){
        printf("a%d = %d \n",i,a[i]);
        printf("b%d = %d \n",i,b[i]);
    }
    my_memcpy(&b , &a , sizeof(a));
    printf("After :");
    for(int i = 0 ; i < 4 ; i++){
        printf("a%d = %d \n",i,a[i]);
        printf("b%d = %d \n",i,b[i]);
    }
    return 0;
}