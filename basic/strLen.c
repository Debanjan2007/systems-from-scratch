#include<stdio.h>

int str_length(char *str){
    size_t length = 0 ;
    while(str[length] != '\0'){
        length++ ;
    }
    if(length == 0){
        return 0;
    }
    return length;
}

int main(int argc , char *argv[]){
    if(argc > 2 || argc <= 1){
        printf("Please enter single word text not a paragraph! LOL");
        return 1;
    }
    int len = str_length(*(argv + 1));  // Another style of writing argv[1]
    printf("Length is: %d",len);
    return 0;
}