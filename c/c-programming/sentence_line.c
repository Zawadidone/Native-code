#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[25];

    printf("Enter a sentence of max %lu characters\n", sizeof(buffer));

    fgets(buffer, sizeof(buffer), stdin);

    for (int i = 0; i < strlen(buffer); i++){
        if (buffer[i] == 32){
            printf("\n");
        }
        printf("%c", buffer[i]);
    }
}

