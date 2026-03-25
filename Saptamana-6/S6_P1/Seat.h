#pragma once
#include "Car.h"

class Seat : public Car {
    float ecoEfficiencyBonus;
public:
    Seat();
    float GetAverageSpeed(Weather weather) override;
    float GetMaxDistance() override;
};