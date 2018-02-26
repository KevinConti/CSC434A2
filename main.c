//Author: Kevin Conti
//Date Written: 02/26/2018

#include <stdio.h>
#include <stdlib.h>

int globalInt = 3;
double globalDouble = 3.0;
char globalChar = '3';
void part1(int, double, char);
int factorial(int);
void part3();

//Purpose: Calls all three of the methods in this file, each one performs one part of the assignment
//For more detail see comments on each method
int main() {
    int paramInt = 8, factorialValue;
    double paramDouble = 8.0;
    char paramChar = '8';
    part1(paramInt, paramDouble, paramChar);
    factorialValue = factorial(6);
    printf("\nFactorial value is: %d\n", factorialValue);
    part3();
    return 0;
}

//Purpose: This method prints out the locations of global, static, local, parameter, and literal values
//Besides being printed the parameters have no utility
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

//Purpose: This Algorithm returns n! factorial, where n = the integer sent in the parameter
//this algorithm is implemented in a recursive function
//Parameter: power: the current value of n
//Returns: The value of n!
int factorial(int power){
    int factorialValue;

    //base caase
    if(power <= 1){
        factorialValue = 1;

        //print statements for part 2
        printf("factorialValue location: %p\n", (void *)&factorialValue);
        printf("factorialValue value: %d\n", factorialValue);

        return factorialValue;
    } else {
        //Progress step (n! = n * (n-1)!)
        factorialValue = factorial(power - 1) * power;

        //Print statements for part 2
        printf("factorialValue location: %p\n", (void *)&factorialValue);
        printf("factorialValue value: %d\n", factorialValue);
        return factorialValue;
    }
}

//Purpose: Construct a multi-dimensional array, iterate through the array and print the location of each entry
//The goal of this algorithm is to determine whether C uses row-major or column-major ordering for arrays
void part3(){
    double array[4][2][3];
    int i, j, k, tables, rows, columns;
    tables = sizeof(array) / sizeof(array[0]);
    rows = sizeof(array[0]) / sizeof(array[0][0]);
    columns = sizeof(array[0][0]) / sizeof(array[0][0][0]);
    for(i = 0; i < tables; i++){
        for(j=0; j < rows; j++){
            for(k=0; k < columns; k++){
                //If these print in order, C is row-major
                printf("Address of [%d][%d][%d]: %p\n", i,j,k, (void *)&array[i][j][k]);
            }
        }
    }
}