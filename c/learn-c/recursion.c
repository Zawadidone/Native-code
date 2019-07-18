#include <stdio.h>


unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 1 || y == 1)
    {
        return y;
    }
    else if (x == 0 || y == 0)
    {
       return 0;
    }
    else
    {
        return y + multiply(x-1, y);
    }
}

int main (void)
{
    printf("3 times 5 is %d\n", multiply(3, 5));
    printf("1 times 7 is %d\n", multiply(1, 7));
}
