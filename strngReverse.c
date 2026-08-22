#include<stdio.h>
#include<string.h> // this header file is required for the strlen function

/* 
 * This is a simple C program that reverses a string.
 * Algorithm:
 * 1. Read the input string from the user.
 * 2. Calculate the length of the string.
 * 3. Use a loop to swap characters from the start and end of the string until the middle is reached. Kinda like a two-pointer technique.
 * 4. Print the reversed string.
*/

int main(int argc, char *argv[]){
    int length = 0; // Variable to store the length of the string
    for(int i = 1 ; i < argc ; i++){
        length += strlen(argv[i]); // Calculate the length of the string
    }
    if(length >= 100 || length < 1){
        printf("Error: Input string is too long or too short. Maximum length is 99 characters.\n");
        return 1; // Exit the program with an error code
    }
    for(int i = 1 ; i < argc ; i++){
        int left = 0; // Initialize left pointer
        int right = strlen(argv[i]) - 1; // Initialize right pointer
        while(left < right){
            char temp = argv[i][left];
            argv[i][left] = argv[i][right];
            argv[i][right] = temp;
            left++;
            right--;
        }
    }
    printf("Reversed string: ");
    for(int i = 1 ; i < argc ; i++){
        printf("%s ", argv[i]); // Print the reversed string
    }
    return 0;
} 