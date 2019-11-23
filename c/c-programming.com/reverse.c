#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[20];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    unsigned long int count = strcspn(string, "\n");

    for (int i = (int)count; i >= 0; i--){
        printf("%c", string[i]);
    }

    return 0;
}
