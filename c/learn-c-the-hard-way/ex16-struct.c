#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};


void Person_print(struct Person who)
{
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
    struct Person joe;
    joe.name = "Joe";
    joe.age = 52;
    joe.height = 62;
    joe.weight = 180;
    Person_print(joe);

    struct Person frank;
    frank.name = "Frank";
    frank.age = 40;
    frank.height = 70;
    frank.weight = 200;
    Person_print(frank);

    return 0;
}
