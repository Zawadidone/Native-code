#include <stdarg.h>
#include <stdio.h>

float average (int n_args, ...)
{
    va_list  myList;

    // length of list
    va_start(myList, n_args);

    int numbersAdded = 0;
    int sum = 0;

    while (numbersAdded < n_args)
    {
        int number = va_arg (myList, int); // next number from list
        sum += number;
        numbersAdded += 1;
    }

    va_end (myList);

    float avg = (float)(sum) / (float)(numbersAdded); // average
    return avg;
}

int main(void)
{
    float avg;
    avg = average(2, 10, 20);

    printf("%f", avg);

    return 0;
}
