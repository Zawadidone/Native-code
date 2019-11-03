#include <stdio.h>

int main(void)
{
    char str[] = "I am string\n";

    char * str_pointer = (char *) &str;

    printf("%s", str);
    printf("%s", str_pointer);

    return 0;
}
