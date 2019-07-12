#include <stdio.h>

int sum (int num)
{
    /**
    * find sum to n numbers
    */
    static int sum;

   return sum+= num;
}

int main(void)
{
    printf("%d ",sum(55));
    printf("%d ",sum(45));
    printf("%d ",sum(50));
    return 0;
}
