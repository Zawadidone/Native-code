#include <stdio.h>

int main(void)
{
    enum weather {
        sunny,
        windy,
        cloudy,
        rain,
    } weather_outside;

    weather_outside = 0;

    switch (weather_outside)
    {
        case sunny:
            printf("Sunny: 0");
            break;
        case windy:
            printf("Windy: 1");
            break;
        case cloudy:
            printf("Cloudy: 2");
            break;
        case rain:
            printf("Rain: 3");
            break;
    }

    return 0;
}
