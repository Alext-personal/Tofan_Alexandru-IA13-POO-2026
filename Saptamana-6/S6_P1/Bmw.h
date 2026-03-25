#pragma once
#include "Car.h"

class Bmw : public Car {
    float sportModeBonus;
public:
    Bmw();
    float GetAverageSpeed(Weather weather) override;
    float GetMaxDistance() override;
};