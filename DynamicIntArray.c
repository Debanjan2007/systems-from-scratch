#include<stdio.h>
#include<stdlib.h>

int main(){
    int n ;
    printf("How many integers do you wanna put ? ");
    scanf("%d",&n);
    int *arr = malloc((sizeof(int)) * n);
    if(arr == NULL){
        printf("Heap overflow!");
        return 1;
    }
    printf("The arr is: %p",(void *)arr);
    puts("");
    for(int i = 0 ; i < n ; i++){
        int temp ;
        printf("Enter %dth element: ",i);
        scanf("%d",&temp);
        *(arr + i) = temp ;
    }
    printf("\nThe array is :\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}