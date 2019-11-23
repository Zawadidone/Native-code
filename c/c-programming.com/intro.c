#include <stdio.h>

int main(void)
{
    char number[4];

    fgets(number, sizeof(number), stdin);

    printf("%s", number);

    return 0;
}
