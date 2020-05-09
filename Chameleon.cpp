#include "Chameleon.h"


Chameleon::Color::Color()  :
red(0),
green(135),
blue(25),
alpha(255)
{
            
}

void Chameleon::Color::setColor(int newRedValue, int newGreenValue, int newBlueValue)
{
    red = newRedValue;
    green = newGreenValue;
    blue = newBlueValue;
}

void Chameleon::Color::setAlpha(int newAlphaValue)
        {
            alpha = newAlphaValue;
        }



Chameleon::Chameleon() :
numberOfTeeth(35),
numberOfScales(4800),
totalTongueFlickDistance(0)
{
    std::cout << "<Chameleon> was created." << std::endl;
}

Chameleon::~Chameleon()
{
    std::cout << "Chameleon::Chameleon() called" << std::endl;
    flickTongue(0.4f, 2);
}

float Chameleon::run(float speed, float timeToRun)
{
    return speed * timeToRun;
}

void Chameleon::changeColor(int newRedValue, int newGreenValue, int newBlueValue)
{
    std::cout << "Chamelon: Current RGB color is (" <<
        color.red << ", " << color.green << ", " << color.blue << ")" << std::endl;

    color.setColor(newRedValue, newGreenValue, newBlueValue);

    std::cout << "Chameleon changed color!  New RGB value is (" <<
        newRedValue << ", " << newGreenValue << ", " << newBlueValue << ")" << std::endl;
}

void Chameleon::flickTongue(float flickDistance, int numberOfFlicks)
{
    totalTongueFlickDistance += numberOfFlicks * flickDistance;

    std::cout << "Chameleon flicked its tongue " << numberOfFlicks << 
        " times! Total tongue flick distance is now " << totalTongueFlickDistance <<
        " inches." << std::endl;
}

void Chameleon::eat (int fliesToEat) 
{
    float weightGained = 0.0f;

    std::cout << "Chameleon is eating " << fliesToEat << " flies!" << std::endl;

    for(int fliesEaten = 0; fliesEaten < fliesToEat; ++fliesEaten)
    {
        weightGained += 0.1f;

        std::cout << "Ate a fly and gained 0.1" << std::endl;
    }

    std::cout << "Chameleon gained a total of " << weightGained << std::endl;
    weight += weightGained;
}

void Chameleon::printNumberOfTeeth()
{
    std::cout << "This Chameleon has " << this->numberOfTeeth << " teeth." << std::endl;
}

void Chameleon::printNumberOfScales()
{
    std::cout << "This Chameleon has " << this->numberOfScales << " scales." << std::endl;
}

void Chameleon::printWeight()
{
    std::cout << "This Chameleon weighs " << this->weight << std::endl;
}
