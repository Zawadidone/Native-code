#include <stdio.h>

void add(int * i)
{
    (*i)++;
}

int main (void)
{
    int i;

    printf("Before: %d\n", i);

    add(&i);

    printf("After: %d\n", i);

}
