#include<stdio.h>
#define SIZE 5
int stack[SIZE] = {0};
int top = -1;

void push(int num){
    if(top == SIZE - 1){
        perror("Error: Stack overflow\n");
        return;
    }
    stack[++top] = num;
    printf("%d is pushed\n",num);
    return;
}

void pop(){
    if(top == -1){
        perror("Error: Stack underflow\n");
        return;
    }
    top--;
    printf("Poped\n");
    return;
}

void read(){
    if(top == -1){
        printf("Nothing to return\n");
        return;
    }
    int i = 0;
    while(i <= top){
        printf("%d\n",stack[i]);
        i++;
    }
}

int main(){
    printf("********************Stack********************\n");
    for(int i = 0 ; i < 5 ; i++){
        int temp;
        printf("Enter %dth position : ",i);
        scanf("%d",&temp);
        push(temp);
    }
    pop();
    read();
    printf("Comeplete");
    return 0;
}