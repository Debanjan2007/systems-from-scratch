# C programs

*this repo is all about my re-learning of C*

| Table of content | Completed |
| --------------------- | :---------: |
| Calculator | ✅ |
| Number Analyzer | ✅ |
| String Reverse | ✅ |
| Pointer Swap | ✅ |
| strlen() | ✅ |
| memcpy() | ✅ |

Copy code

```bash
    git clone https://github.com/Debanjan2007/c-programs.git Cprogram
    cd Cprogram
```

# Calculator in C

Here is a CLI calculator program written in C. It can perform basic arithmetic operations like addition, subtraction, multiplication, and division. Division result is not a double, it is an integer. The program takes two numbers and an operator as input from the user and displays the result.

## how to run the program

Compile and run the program using the following commands:

```bash
    gcc calc.c -o calc
    ./calc 24 + 12
```

## output

```bash
    The result is: 36
```

# Number Analyzer in C

This program takes a list of numbers as command line arguments and analyzes them to find the count, minimum, maximum, and average of the numbers. The program uses the `atoi` function to convert the command line arguments from strings to integers.

## how to run the program

Compile and run the program using the following commands:

```bash
    gcc numAnalyzer.c -o numAnalyzer
    ./numAnalyzer 1 2 3 4 5
```

## output

```bash
    Count: 5
    Minimum: 1
    Maximum: 5
    Average: 3.00
```

# String Reverse in C

This program takes a list of strings as command line arguments and reverses the order of the strings. The program uses a simple algorithm to swap the first and last strings, then the second and second last strings, and so on until all the strings are reversed.

## How to run the program

```bash
    gcc strngReverse.c -o strngReverse
    ./strngReverse "Hello" "World" "C" "Programming"
```

## Output

```bash
    Reversed string: gnimmargorP C dlroW olleH
```

# String Length

Built my own string lenggth calculator. It takes an array of charecters or a string and returns the length of the string.

## How to run the program

```c
    gcc .\strLen.c -o strlen
    ./strlen "Hello World"
```

## Output

```c
    Length is: 11
```

## Copy of memcpy()

memcpy() takes destination and source with the size in bytes.I build my_memcpy().

## How to use the program

### Input

```c
    int main(){
        int a[] = {1 , 25 , 45 , 88};
        int b[4];
        printf("Before :");
        for(int i = 0 ; i < 4 ; i++){
            printf("a%d = %d \n",i,a[i]);
            printf("b%d = %d \n",i,b[i]);
        }
        my_memcpy(&b , &a , sizeof(a));
        printf("After :");
        for(int i = 0 ; i < 4 ; i++){
            printf("a%d = %d \n",i,a[i]);
            printf("b%d = %d \n",i,b[i]);
        }
        return 0;
    }
```

Run

```bash
    gcc myMemcpy.c -o memcpy
    ./memcpy
```

## Output

```bash
    Before :a0 = 1 
    b0 = -2 
    a1 = 25 
    b1 = 6422280 
    a2 = 45 
    b2 = 1987415069 
    a3 = 88 
    b3 = 4201056 
    After :a0 = 1 
    b0 = 1 
    a1 = 25 
    b1 = 25 
    a2 = 45 
    b2 = 45 
    a3 = 88 
    b3 = 88 
```

> Built for learning by `Debanjan`
