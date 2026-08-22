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

int main(){
    char str[] = "H";
    int len = str_length(str);
    printf("Length is: %d",len);
    return 0;
}