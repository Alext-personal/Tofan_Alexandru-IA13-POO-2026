#include "Bmw.h"

Bmw::Bmw() {
    fuelCapacity = 60;
    fuelConsumption = 11; 
    averageSpeed[0] = 130;  
    averageSpeed[1] = 80;
    averageSpeed[2] = 40; 
    sportModeBonus = 15;
    name = new char[10]{"Bmw"};
}

float Bmw::GetAverageSpeed(Weather weather) {
    if (weather == Weather::Sunny)
        return averageSpeed[weather] + sportModeBonus;
    return averageSpeed[weather];
}

float Bmw::GetMaxDistance() {
    return (float)(fuelCapacity / fuelConsumption) * 100;
}