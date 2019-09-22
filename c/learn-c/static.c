#include <stdio.h>

int sum (int num)
{
    /**
    * find sum to n numbers
    */
    static int sum;

   return sum+= num;
}

int sum_non_static (int num_non_static)
{
    int sum_non_static = 0;

    sum_non_static += num_non_static;

    return sum_non_static;
}

int main(void)
{

    printf("%d ",sum(55));
    printf("%d ",sum(45));
    printf("%d ",sum(50));
    printf("%d ",sum_non_static(55));
    printf("%d ",sum_non_static(45));
    printf("%d ",sum_non_static(50));
    return 0;
}
