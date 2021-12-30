#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 2700

// bigiNT

void removeZero(char *bigInt)
{
    int i = 0, j = 0;
    while (bigInt[i] == '0')
    {
        i++;
    }

    if (i == 0)
    {
        bigInt[1] = '\0';
        return;
    }

    for (j; j + i <= MAX_DIGITS + 1; j++)
    {
        bigInt[j] = bigInt[j + i];
    }

    bigInt[j] = '\0';

    return;
}

char *initializebigiNT()
{
    char *bigiNT = (char *)malloc(sizeof(char) * (MAX_DIGITS + 2));

    for (int i = 0; i < MAX_DIGITS + 1; i++)
    {
        bigiNT[i] = '0';
    }

    bigiNT[MAX_DIGITS + 1] = '\0';

    return bigiNT;
}

int comparebigiNT(char *bigiNT1, char *bigiNT2)
{
    int s1 = strlen(bigiNT1);
    int s2 = strlen(bigiNT2);

    if (s1 > s2)
    {
        return 1;
    }
    else if (s1 < s2)
    {
        return -1;
    }
    else
    {
        for (s1; s1 >= 0; --s1)
        {
            if (bigiNT1[s1] > bigiNT2[s1])
            {
                return 1;
            }
            else if (bigiNT1[s1] < bigiNT2[s1])
            {
                return -1;
            }
        }
    }

    return 0;
}

char *addition(char *bigiNT1, char *bigiNT2)
{
    int s1 = strlen(bigiNT1) - 1;
    int s2 = strlen(bigiNT2) - 1;

    char *result = initializebigiNT();

    int carry = 0;
    int i = MAX_DIGITS;

    while (s1 >= 0 || s2 >= 0)
    {
        int sum = carry;

        if (s1 >= 0)
        {
            sum += (bigiNT1[s1] - '0');
            s1--;
        }

        if (s2 >= 0)
        {
            sum += (bigiNT2[s2] - '0');
            s2--;
        }

        result[i] = sum % 10 + '0';
        carry = sum / 10;

        --i;
    }

    if (carry > 0)
    {
        result[i] = carry + '0';
        --i;
    }
    removeZero(result);

    return result;
}

char *difference(char *bigiNT1, char *bigiNT2)
{
    int x = comparebigiNT(bigiNT1, bigiNT2);
    char *result = initializebigiNT();

    int borrow = 0;
    int i = MAX_DIGITS;

    if (x == -1)
    {
        char *temp = bigiNT1;
        bigiNT1 = bigiNT2;
        bigiNT2 = temp;
    }

    int s1 = strlen(bigiNT1) - 1;
    int s2 = strlen(bigiNT2) - 1;

    int diff = 0;
    while (s1 >= 0)
    {

        if (s2 >= 0)
        {
            diff += bigiNT1[s1] - bigiNT2[s2] - borrow;
            s2--;
        }
        else
        {
            diff += bigiNT1[s1] - '0';
        }

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result[i] = diff + '0';
        diff = 0;
        --i;
        --s1;
    }
    removeZero(result);
    return result;
}

char *multiplication(char *bigiNT1, char *bigiNT2)
{
    char *result = initializebigiNT();

    if (strcmp(bigiNT1, "0") == 0 || strcmp(bigiNT2, "0") == 0)
    {
        result[1] = '\0';
        return result;
    }

    if (strcmp(bigiNT1, "1") == 0)
    {
        free(result);
        return bigiNT2;
    }

    if (strcmp(bigiNT2, "1") == 0)
    {
        free(result);
        return bigiNT1;
    }

    int x = comparebigiNT(bigiNT1, bigiNT2);

    if (x == -1)
    {
        char *temp = bigiNT1;
        bigiNT1 = bigiNT2;
        bigiNT2 = temp;
    }

    int s1 = strlen(bigiNT1) - 1;
    int s2 = strlen(bigiNT2) - 1;
    int l = MAX_DIGITS;

    for (int i = s2, k = 0; i >= 0; --i, ++k)
    {
        int sum = 0, carry = 0;
        int ptr = l - k;

        for (int j = s1; j >= 0; --j, --ptr)
        {
            sum = (bigiNT1[j] - '0') * (bigiNT2[i] - '0') + carry;
            result[ptr] += sum % 10;
            carry = sum / 10;

            if (result[ptr] > '9')
            {
                result[ptr] -= 10;
                result[ptr - 1] += 1;
            }
        }

        if (carry > 0)
        {
            result[ptr] += carry;
        }
    }

    removeZero(result);
    return result;
}

char *fibonaccibigiNT(int n)
{
    char *result = initializebigiNT();

    if (n == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    if (n == 1)
    {
        result[0] = '1';
        result[1] = '\0';
        return result;
    }

    char *prev = initializebigiNT();
    prev[0] = '0';
    prev[1] = '\0';

    char *curr = initializebigiNT();
    curr[0] = '1';
    curr[1] = '\0';

    for (int i = 2; i <= n; ++i)
    {
        char *temp = addition(prev, curr);
        free(prev);
        prev = curr;
        curr = temp;
    }

    free(prev);
    return curr;
}

char *factorialbigiNT(int n)
{
    char *result = initializebigiNT();
    result[0] = '1';
    result[1] = '\0';

    if (n == 0 || n == 1)
    {
        return result;
    }

    char *curr = initializebigiNT();
    curr[0] = '1';
    curr[1] = '\0';

    char *unit = initializebigiNT();
    unit[0] = '1';
    unit[1] = '\0';

    for (int i = 2; i <= n; ++i)
    {
        curr = addition(curr, unit);
        char *temp = multiplication(result, curr);
        free(result);
        result = temp;
    }

    return result;
}
