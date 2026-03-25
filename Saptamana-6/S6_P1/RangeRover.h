#pragma once
#include "Car.h"

class RangeRover : public Car {
    float allWeatherSpeedBonus;
public:
    RangeRover();
    float GetAverageSpeed(Weather weather) override;
    float GetMaxDistance() override;
};