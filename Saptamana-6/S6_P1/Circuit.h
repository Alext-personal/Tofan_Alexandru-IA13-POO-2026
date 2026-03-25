#pragma once
#include "Car.h"
class Circuit
{
    
    int length;
    Weather weather;
    Car* cars[16];
    Car* ranks[16];
    int numberOfCars;
public:
    Circuit();
    void SetLength(int newLength);
    void SetWeather(Weather newWeather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
