#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char stars[4];

    printf("Enter a length(int): ");
    fgets(stars, sizeof(stars), stdin);

    for (int i = 1; i <= atoi(stars); i++){
        for (int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
