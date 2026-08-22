#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

int main(int argc , char *argv[]){
    if(argc < 1 || argc > 3){
        printf("Error: program terminated ,Memory overflow");
        return 1;
    }
    int num1 , num2 = 0;
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    printf("num1 %d num2 %d\n",num1,num2);
    swap(&num1 , &num2);
    printf("num1 %d num2 %d",num1,num2);
    return 0;
}