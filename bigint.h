// If bigint.h is not included to any file
#ifndef BIGINT_H

// Declare macro as a flag that specifies bigint.h is included
#define BIGINT_H

// Declare all functions
void removeZero(char *bigInt);
char *initializebigiNT();
int comparebigiNT(char *bigiNT1, char *bigiNT2);
char *addition(char *bigiNT1, char *bigiNT2);
char *difference(char *bigiNT1, char *bigiNT2);
char *multiplication(char *bigiNT1, char *bigiNT2);
char *fibonaccibigiNT(int n);
char *factorialbigiNT(int n);

#endif