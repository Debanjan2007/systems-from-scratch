#include<stdio.h>
#include<stdlib.h>

char *stack ;
int top = -1 ;
const start_size = sizeof(char) * 4;
int capacity = start_size;

void push(char ch){
    if(top == start_size - 1){
        capacity *= 2 ;
        stack = realloc(stack, capacity); // reallocating memory by one
        stack[++top] = ch;
        return;
    }
    stack[++top] = ch;
    return;
}

void read(){
    if(top < 0){
        perror("Error: nothing ini the memory\n");
        return ;
    }
    for(int i = 0 ; i <= top ; i++){
        printf("%c",stack[i]);
    }
    printf("\nEOF");
    return ;
}

int main(){
    stack = malloc(start_size); // starting with 4 bytes
    int ch ; 
    printf("Enter your string:");
    while((ch = getchar()) != '\n' && ch != EOF){
        printf("Loop grabbed: %c\n", ch);
        push(ch);
    }
    read();
    free(stack);
    return 0;
}