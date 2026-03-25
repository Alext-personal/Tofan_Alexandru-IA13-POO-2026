#pragma once
#include "Car.h"

class Volvo: public Car
{
    float snowSpeedBonus;
public:
    Volvo();
    float GetAverageSpeed(Weather weather) override;
    float GetMaxDistance() override;
};
