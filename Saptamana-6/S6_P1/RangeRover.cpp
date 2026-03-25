#include "RangeRover.h"

RangeRover::RangeRover() {
    fuelCapacity = 95;
    fuelConsumption = 25;
    averageSpeed[0] = 90; 
    averageSpeed[1] = 110; 
    averageSpeed[2] = 90; 
    allWeatherSpeedBonus = 10;
    name = new char[12]{"RangeRover"};
}

float RangeRover::GetAverageSpeed(Weather weather) {
    return averageSpeed[weather] + allWeatherSpeedBonus;
}

float RangeRover::GetMaxDistance() {
    return (float)(fuelCapacity / fuelConsumption) * 100;
}