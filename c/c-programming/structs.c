#include <stdio.h>

int main(void)
{
    struct mystruct {
        int int_member;
        double double_member;
        char string_member[25];
    } struct_var;

    struct_var.int_member = 0;
    //struct_var->int_member = 0; // it's a pointer ...
    struct_var.string_member[25] = "xxxxxxxxxxxxxxxx";

    union {
        int i;
        double d;
    } u;

    return 0;
}
