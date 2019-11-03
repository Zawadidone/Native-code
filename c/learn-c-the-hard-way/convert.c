#include <stdio.h>

int main(void)
{
    char name[] = "Piet";
    char *name_pointer = "Piet";

    printf("%s, %s, %p", name, name_pointer, name_pointer);

    return 0;
}
