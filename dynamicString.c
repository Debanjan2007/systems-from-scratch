#include<stdio.h>
#include<stdlib.h>

char *stack ;
int top = -1 ;
const int start_size = sizeof(char) * 4;
int capacity = 4; // set to 4 as start_size is 4bytes

void push(char ch){
    if(top == capacity - 1){
        capacity *= 2 ;
        char *temp = realloc(stack, capacity); // reallocating memory
        if(temp == NULL){
            free(stack);
            perror("Error: Reallocation failed\n");
            return;
        }
        stack = temp;
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
    printf("%s",stack);
    printf("\nEOF");
    return ;
}

int main(){
    stack = malloc(start_size); // starting with 4 bytes
    if(stack == NULL){
        perror("Error: Stack allocation failed!\n");
        return 1;
    }
    int ch ; 
    printf("Enter your string:");
    while((ch = getchar()) != '\n' && ch != EOF){
        push(ch);
    }
    stack[++top] = '\0';
    read();
    free(stack);
    return 0;
}