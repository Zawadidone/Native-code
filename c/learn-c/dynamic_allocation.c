#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    typedef struct {
        int age;
        char * name;
    } person;

    // allocate memory
    person * john = malloc(sizeof(person));

    john->age = 20;
    john->name = "John";
    
    free(john);

    return 0;
}
