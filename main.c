#include <stdio.h>
#include <stdlib.h>

int globalInt = 3;
double globalDouble = 3.0;
char globalChar = '3';
void part1(int, double, char);
int factorial(int);

int main() {
    int paramInt = 8, factorialValue;
    double paramDouble = 8.0;
    char paramChar = '8';
    part1(paramInt, paramDouble, paramChar);
    factorialValue = factorial(6);
    printf("\nFactorial value is: %d\n", factorialValue);
    return 0;
}

void part1(int paramInt, double paramDouble, char paramChar){
    int localInt;
    int *dynamicInt;
    double localDouble;
    double* dynamicDouble;
    char localChar;
    char* dynamicChar, *literalChar;
    void* literalCharPtr;

    localInt = 4;
    localDouble = 4.0;
    localChar = '4';

    static int staticInt = 6;
    static double staticDouble = 6.0;
    static char staticChar = '6';

    dynamicInt = (int*)calloc(1, sizeof(int));
    dynamicDouble = (double*) calloc(1, sizeof(double));
    dynamicChar = (char*) calloc(1, sizeof(char));

    literalChar = "String literal";
    literalCharPtr = &literalChar;

    puts("\nParam Variables:");
    printf("int: %p\ndouble: %p\nchar: %p\n\n", (void*) &paramInt, (void*) &paramDouble, (void*) &paramChar);

    puts("Local Varibles:");
    printf("int: %p\ndouble: %p\nchar: %p\n\n", (void*) &localInt, (void*) &localDouble, (void*) &localChar);

    puts("Static variables:");
    printf("int: %p\ndouble: %p\nchar: %p\n\n", (void*) &staticInt, (void*) &staticDouble, (void*) &staticChar);

    puts("Global variables:");
    printf("int: %p\ndouble: %p\nchar: %p\n\n", (void*) &globalInt, (void*) &globalDouble, (void*) &globalChar);

    puts("Dynamic variables:");
    printf("int: %p\ndouble: %p\nchar: %p\n\n", dynamicInt, dynamicDouble, dynamicChar);

    puts("Function addresses:");
    printf("main: %p\n'part1': %p\n\n", (void*) main, (void*)part1);

    puts("String literals:");
    printf("Literal: %p\n\n", literalCharPtr);
}

//This Algorithm returns n! factorial, where n = the integer sent in the parameter
//this algorithm is implemented in a recursive function
int factorial(int power){
    int factorialValue;

    //base caase
    if(power <= 1){
        return 1;
    } else {
        //Progress step
        factorialValue = factorial(power - 1) * power;
        return factorialValue;
    }
}