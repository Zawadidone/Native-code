#include <stdio.h>

struct Person{
    char name[10];
    int age;
};

int main(void)
{
    struct Person *piet;

    piet->name = strncpy(piet->name, "Piet", sizeof(piet->name));
    piet->age = 10;

    return 0;
}
