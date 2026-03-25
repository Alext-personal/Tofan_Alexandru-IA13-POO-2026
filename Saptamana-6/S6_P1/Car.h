#pragma once
#include "Weather.h"
class Car
{
protected:
    char* name;
    float fuelCapacity; // liters
    float fuelConsumption; // liters/100km
    float averageSpeed[3];
public:
    char* GetName(){return name;}
    virtual float GetAverageSpeed(Weather weather) = 0;
    virtual float GetMaxDistance() = 0;
};