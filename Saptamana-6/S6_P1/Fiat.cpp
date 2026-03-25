#include "Fiat.h"

Fiat::Fiat() {
    fuelCapacity = 35;
    fuelConsumption = 5.5;
    averageSpeed[0] = 90; 
    averageSpeed[1] = 85;
    averageSpeed[2] = 40; 
    rainSpeedBonus = 5;
    name = new char[10]{"Fiat"};
}

float Fiat::GetAverageSpeed(Weather weather) {
    if (weather == Weather::Rain)
        return averageSpeed[weather] + rainSpeedBonus;
    return averageSpeed[weather];
}

float Fiat::GetMaxDistance() {
    return (float)(fuelCapacity / fuelConsumption) * 100;
}