#include "Circuit.h"
#include <cstdio>

Circuit::Circuit()
{
    numberOfCars = 0;
    weather = Weather::Sunny;
    length = 0;
}

void Circuit::SetLength(int newLength)
{
    length = newLength;
}

void Circuit::SetWeather(Weather newWeather)
{
    weather = newWeather;
}

void Circuit::AddCar(Car* car)
{
    cars[numberOfCars] = car;
    numberOfCars++;
}

void Circuit::Race()
{
    for (int i = 0; i < numberOfCars; i++)
        ranks[i] = cars[i];
    for (int i = 0; i < numberOfCars - 1; i++)
        for (int j = i + 1; j < numberOfCars; j++)
        {
            if (ranks[i]->GetAverageSpeed(weather) < ranks[j]->GetAverageSpeed(weather))
            {
                Car* aux = ranks[i];
                ranks[i] = ranks[j];
                ranks[j] = aux;
            }
        }
}

void Circuit::ShowFinalRanks()
{
    for (int i = 0; i < numberOfCars; i++)
        printf("Rank %d : %s\n ",i+1,ranks[i]->GetName());
}

void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < numberOfCars; i++)
        if (ranks[i]->GetMaxDistance() < length)
            printf("Max distance is less than circuit length for %s \n",ranks[i]->GetName());
}


