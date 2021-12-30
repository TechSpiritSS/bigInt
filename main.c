#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigint.h"

int main()
{
    // char *A = "40320";
    // char *B = "9";
    // char *result = addition(A,B);

    int n = 1000;
    char *result = factorialbigiNT(n);
    printf("Factorial of %d is \n%s\n", n, result);
    printf("\n It contains %d digits", strlen(result));

    free(result);
    return 0;
}