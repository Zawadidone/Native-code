#include <stdio.h>

// power: raise base to n-th power; n >= 0

int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; n--)
        p = p * base;
    return p;
}

int main(void)
{
    printf("%d", power(2,5));

    return 0;
}
