#include <stdio.h>

/* define the person struct here using the typedef syntax */

int main() {
    typedef struct {
        char * name;
        int age;
    } person;

    person john;

    /* testing code */
    john.name = "John";
    john.age = 27;

    printf("%s is %d years old.", john.name, john.age);

    return 0;
}
