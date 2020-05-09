#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"
#include "Chameleon.h"

struct FastFoodRestaurant
{
    float profitPerBurger {1.65f};
    float profitPerPotato {0.49f};
    float totalProfits {0.0f};
    int burgersSold = 0;
    int potatoesSold = 0;
    int burgersInFreezer;
    int potatoesInPantry;

    FastFoodRestaurant();
    ~FastFoodRestaurant();
    bool makeBurger(int numBurgers);
    bool makeFries(int potatoesToUse);
    void restockSupplies(int newPotatoes, int newBurgers);
    bool makeChameleonBurger(Chameleon& chameleon);
    void calculateProfit();
    void printTotalProfits();
    void printProfitPerBurger();
    void printProfitPerPotato();

    JUCE_LEAK_DETECTOR(FastFoodRestaurant)
};
