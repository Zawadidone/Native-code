#include <stdio.h>

int main(void)
{
    int i = 0;
    int j = 0;

    // while i is less than 5 AND j is less than 5, loop
    while ((i < 5) && (j < 5))
    {
        /* postfix increment, i++
        * the value of i is read and then incremented */
        printf("i: %d\t", i++);

        /* prefix increment, ++j
         * the value of j is incremented and then read */
        printf("j: %d\n", ++j);
    }

    printf("At the end they have both equal values:\ni: %d\tj: %d\n", i, j);

    getchar(); //pause

    return 0;
}
