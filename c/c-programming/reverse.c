#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[25];

    printf("Enter a string of max %lu characters\n", sizeof(buffer));

    fgets(buffer, sizeof(buffer), stdin);

    for (int i = (int) strlen(buffer) - 1; i > -1; i--){
        printf("%c", buffer[i]);
    }
}
