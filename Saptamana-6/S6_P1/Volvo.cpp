#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 50;
    fuelConsumption = 70;
    averageSpeed[0] = 50;
    averageSpeed[1] = 40;
    averageSpeed[2] = 30;
    snowSpeedBonus = 10;
    name = new char[10]{"Volvo"};
}
float Volvo::GetAverageSpeed(Weather weather)
{
    if (weather == Weather::Snow)
        return averageSpeed[weather]+snowSpeedBonus;
    return averageSpeed[weather];
}    

float Volvo::GetMaxDistance()
{
    return (float)(fuelCapacity / fuelConsumption)*100;
}

