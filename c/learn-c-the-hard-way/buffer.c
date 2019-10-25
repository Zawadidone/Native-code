#include <stdio.h>

int main(void)
{
    char input[20];

    fgets(input, 20, stdin);

    printf("You entered: %s", input);

    return 0;
}
