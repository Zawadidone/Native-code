#include <stdio.h>

// this is the function to compute the absolute value of a whole number

int abs(int x)
{
    if(x>=0) return x;
    else return -x;
}

// this is the program that uses twice the function defined above
int main(void)
{
    int x, y;

    printf("Type the coordinates of a point in 2-plane, say P = (x,y). First x=");
    scanf("%d", &x);
    printf("Second y=");
    scanf("%d", &y);

    printf("The distance of the P point to the x-axis is %d. \nIts distance to the y-axis is %d. \n",
            abs(y), abs(x));

    return 0;
}
