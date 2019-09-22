#include <stdio.h>

int main(void)
{
    int i;

    printf("Enter integer between 1-3:");
    scanf("%d", &i);

    switch(i)
    {
        case 1:
            printf("This code handles case\n");
            break;
        case 2:
            printf("This prints when i is 2\n");
            break;
        case 3:
            printf("This prints when i is 3\n");
            break;
        default:
            printf("lol");
            break;
    }

    return 0;
}
