#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int count , min , max ;
    double sum = 0, avg ;
    min = atoi(argv[1]) ;
    max = atoi(argv[1]) ;
    if(argc < 2){
        printf("Please enter at least one number\n") ;
        return 0 ;
    }
    for (int i = 1 ; i < argc ; i++){
        int temp = 0 ;
        if (argv[i + 1] ==  NULL){
            temp = atoi(argv[i]) ;
        }else {
            temp = atoi(argv[i + 1]) ;
        }
        if (temp < min){
            min = temp ;
        }
        if (temp > max){
            max = temp ;
        }
        sum += atoi(argv[i]) ;
    }
    avg = sum / (argc - 1) ;
    printf("Count: %d\n", argc - 1) ;
    printf("Min: %d\n", min) ;
    printf("Max: %d\n", max) ;
    printf("Average: %.2f\n", avg) ;
    return 0;
}