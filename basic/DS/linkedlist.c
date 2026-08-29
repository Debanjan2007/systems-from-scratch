// Singly linkde list
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next_node;
}node;
node *start = NULL;
void append(int data);
void display();

int main(){
    printf("Welcome to singly linked list\n");
    int input;
    do{
        printf("\nEnter <1> to append <0> to exit: ");
        scanf("%d",&input);
        int val;
        switch (input){
        case 0:
            break;
        case 1:
            printf("Enter a number: ");
            scanf("%d",&val);
            append(val);
        default:
            printf("\nPlease enter a right choice");
            break;
        }
    }while(input != 0);
    display();
    return 0;
}

void append(int data){
    node *temp , *curr ;
    temp = (node *)(malloc(sizeof(node)));
    temp->data = data;
    temp->next_node = NULL;
    if(start == NULL){
        start = temp;
        temp->next_node = NULL;
    }else{
        curr = start;
        while(curr->next_node != NULL){
            curr = curr->next_node;
        }
        curr->next_node = temp;
    }
}

void display(){
    node *curr;
    curr = start;
    if(start == NULL){
        printf("\nList is empty");
    }
    do{
        printf("\n%d",curr->data);
        curr = curr->next_node;
    }while(curr->next_node != NULL);
    return ;
}