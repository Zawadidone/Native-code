#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int arr[] = {10, 20, 30 ,40 , 50, 60};
    int *ptr = arr;

    // size of int * number of elements is printed
    printf("Size of arr[] %d: \n", sizeof(arr));

    // size of a pointer is printed
    printf("Size of ptr %d: %d \n", ptr, sizeof(ptr));

    // modify second value of array by using a pointer
    *(ptr+1) = 100;
    printf("%d \n", arr[1]);

    // initialize a pointer with space for 10 * 4b
    char* array = malloc(50);

    // fill the memory with 7 a's
    memset(array, 'a', 7);

    printf("After memset(): %s \n", array);

    free(array);

    return 0;
}
