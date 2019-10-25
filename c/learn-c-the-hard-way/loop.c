#include <stdio.h>

int main(void)
{
    int i, j;

    i = 0;
    j = 0;

    do
    {
        printf("%d", i);
        i++;
    } while (i < 6);

    while (j < 6)
    {
        printf("%d", j);
        j++;
    }
    return 0;
}
