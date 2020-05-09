#include "FastFoodRestaurant.h"

FastFoodRestaurant::FastFoodRestaurant() :
burgersInFreezer(200),
potatoesInPantry(100)
{
    std::cout << "<FastFoodRestaurant> was created." << std::endl;
}

FastFoodRestaurant::~FastFoodRestaurant()
{
    std::cout << "FastFoodRestaurant::~FastFoodRestaurant() called" << std::endl;
    calculateProfit();
}

bool FastFoodRestaurant::makeBurger(int burgersToMake)
{
    if (burgersInFreezer > 0)
    {
        burgersInFreezer -= burgersToMake;
        burgersSold += burgersToMake;

        std::cout << "Made " << burgersToMake << " burgers. Burgers left in freezer: " << burgersInFreezer << ". Burgers sold: " << burgersSold << std::endl;

        return true;
    }

    return false;
}

bool FastFoodRestaurant::makeFries(int potatoesToUse)
{
    if (potatoesToUse < potatoesInPantry)
    {
        potatoesInPantry -= potatoesToUse;
        potatoesSold += potatoesToUse;

        std::cout << "Made fries using " << potatoesToUse << " potatoes. Potatoes left in freezer: " << potatoesInPantry << ". Potatoes sold: " << potatoesSold << std::endl;

        return true;
    }

    return false;
}

void FastFoodRestaurant::restockSupplies(int newPotatoes, int newBurgers)
{
    potatoesInPantry += newPotatoes;
    burgersInFreezer += newBurgers;

    std::cout << "Restocked supplies. " << std::endl <<
        "Potatoes in pantry: " << potatoesInPantry << std::endl <<
        "Burgers in freezer: " << burgersInFreezer << std::endl;
}

bool FastFoodRestaurant::makeChameleonBurger(Chameleon& chameleon)
{
    chameleon.changeColor(150, 75, 0);
    return true;
}

void FastFoodRestaurant::calculateProfit()
{
    while(burgersSold > 0)
    {
        totalProfits += profitPerBurger;
        --burgersSold;
    }

    while(potatoesSold > 0)
    {
        totalProfits += profitPerPotato;
        --potatoesSold;
    }
}

void FastFoodRestaurant::printTotalProfits()
{
    std::cout << "Current total profits: $" << this->totalProfits << std::endl;
}

void FastFoodRestaurant::printProfitPerBurger()
{
    std::cout << "This restaurant makes $" << this->profitPerBurger << " profit per burger." << std::endl;
}

void FastFoodRestaurant::printProfitPerPotato()
{
    std::cout << "This restaurant makes $" << this->profitPerPotato << " profit per potato." << std::endl;
}
