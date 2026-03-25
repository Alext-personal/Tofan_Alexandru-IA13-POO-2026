#pragma once
#include "Car.h"

class Fiat : public Car {
    float rainSpeedBonus;
public:
    Fiat();
    float GetAverageSpeed(Weather weather) override;
    float GetMaxDistance() override;
};