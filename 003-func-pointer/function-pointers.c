#include <stdio.h>

int add(int a,int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


// Function pointer type definition
typedef int (*operation_t)(int,int);

int main() {
    int x=10,y=5;
    operation_t op;

    op=add;
    printf("Addition: %d\n",op(x,y));
    
    op=subtract;
    printf("Subtraction: %d\n",op(x,y));

    op=multiply;
    printf("Multiplication: %d\n",op(x,y));

    op=divide;
    printf("Division: %d\n",op(x,y));

    return 0;
}

// Function implementations
int add(int a, int b) {return a+b;}
int subtract(int a, int b) {return a-b;}
int multiply(int a, int b) {return a*b;}
int divide(int a, int b) {return b!=0 ? a/b : 0;}
