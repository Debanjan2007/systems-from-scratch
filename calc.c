#include <stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[]) {
    int num1 , num2 , res;
    char operator;
    printf("****** C Calculator ******\n\n");
    if(argc > 4 || argc <= 1){
        printf("Can't calculate, Stack overflow");
        return 0;
    }
    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);
    operator = (char)*argv[2];
    switch(operator){
        case '+': 
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '/':
            if (num2 == 0){
                printf("Division operation can not be donem, Undefined");
                break;
            }
            res = (int) num1 / num2;
            break;
        default:
            printf("\nCan't operate! Please enter a valid operator.");
            return 0;
    }
    printf("The result is: %d\n",res);
    return 0;
}