#include "Seat.h"

Seat::Seat() {
    fuelCapacity = 45;
    fuelConsumption = 7;
    averageSpeed[0] = 100;
    averageSpeed[1] = 80;
    averageSpeed[2] = 60;
    ecoEfficiencyBonus = 0.9f;
    name = new char[10]{"Seat"};
}

float Seat::GetAverageSpeed(Weather weather) {
    return averageSpeed[weather];
}

float Seat::GetMaxDistance() {
    return (float)(fuelCapacity / (fuelConsumption * ecoEfficiencyBonus)) * 100;
}