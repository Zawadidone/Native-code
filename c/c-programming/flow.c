#include <string.h>
#include <stdio.h>

int main(void)
{
    int z = 100;

    char bar[3] = "foo";
    int x;
    if(strstr("foo", bar) >= 0)
    { // bar contains "foo"
        printf("foo\n");
    }

    int value = 20;

    if(0 < value < 10) // don't to this! it always evaluates to "true"!
    {
       printf("TRUE\n");
    }

    if(0 < value && value < 10)
    {
        printf("nope\n");
    }

    return 0;
}
