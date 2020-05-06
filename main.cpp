/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

/*
 copied UDT 1:
 */

#include <iostream>
#include "LeakedObjectDetector.h"

struct Chameleon
{
    struct Color
    {
        int red;
        int green;
        int blue;
        int alpha;

        Color()  :
        red(0),
        green(135),
        blue(25),
        alpha(255)
        {
            
        }

        void setColor(int newRedValue, int newGreenValue, int newBlueValue)
        {
            red = newRedValue;
            green = newGreenValue;
            blue = newBlueValue;
        }

        void setAlpha(int newAlphaValue)
        {
            alpha = newAlphaValue;
        }

        JUCE_LEAK_DETECTOR(Color)
    };

    float length {5.0f};
    float weight {8.0f};
    Color color;
    int numberOfTeeth;
    int numberOfScales;
    float totalTongueFlickDistance;

    Chameleon();
    ~Chameleon();
    float run(float speed, float timeToRun);
    void changeColor(int newRedValue, int newGreenValue, int newBlueValue);
    void flickTongue(float flickDistance, int numberOfFlicks);
    void eat(int fliesToEat);
    void printNumberOfTeeth();
    void printNumberOfScales();
    void printWeight();

    JUCE_LEAK_DETECTOR(Chameleon)
};

struct ChameleonWrapper
{
    Chameleon* chameleon = nullptr;

    ChameleonWrapper(Chameleon* c) : 
    chameleon(c)
    {

    }
    ~ChameleonWrapper()
    {
        delete chameleon;
    }
};

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

/*
 copied UDT 2:
 */
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

struct FastFoodRestaurantWrapper
{
    FastFoodRestaurant* restaurant = nullptr;

    FastFoodRestaurantWrapper(FastFoodRestaurant* ffr) :
    restaurant(ffr)
    {

    }
    ~FastFoodRestaurantWrapper()
    {
        delete restaurant;
    }
};

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
        burgersSold -= 1;
    }

    while(potatoesSold > 0)
    {
        totalProfits += profitPerPotato;
        potatoesSold -= 1;
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

/*
 copied UDT 3:
 */
struct ElectricGuitar
{
    float neckLength;
    float volumeKnobPosition = 1.0f;
    float toneKnobPosition = 1.0f;
    int numberOfPickups;
    int numberOfStrings;

    ElectricGuitar();
    ~ElectricGuitar();
    void outputSound();
    void setVolume(float newVolumePosition);
    void setTone(float newTonePosition);
    void setVolumeGradually(float newVolumePosition);
    void printNeckLength();
    void printNumberOfPickups();
    void printNumberOfStrings();

    JUCE_LEAK_DETECTOR(ElectricGuitar)
};

struct ElectricGuitarWrapper
{
    ElectricGuitar* guitar = nullptr;

    ElectricGuitarWrapper(ElectricGuitar* gtr) :
    guitar(gtr)
    {

    }
    ~ElectricGuitarWrapper()
    {
        delete guitar;
    }
};

ElectricGuitar::ElectricGuitar() :
neckLength(22.5f),
numberOfPickups(3),
numberOfStrings(6)
{
    std::cout << "<ElectricGuitar> was created. This guitar has a " << neckLength << 
        " inch neck and " << numberOfPickups << " pickups." << std::endl;
}

ElectricGuitar::~ElectricGuitar()
{
    std::cout << "ElectricGuitar::~ElectricGuitar() called" << std::endl;
    setVolumeGradually(0.0f);
}

void ElectricGuitar::outputSound()
{
    std::cout << "ElectricGuitar::outputSound() called.  Shredding some hot licks." << std::endl;
}

void ElectricGuitar::setVolume(float newVolumePosition)
{
    volumeKnobPosition = newVolumePosition;

    std::cout << "ElectricGuitar::setVolume(): Volume knob positiion is now " << volumeKnobPosition << std::endl;
}

void ElectricGuitar::setTone(float newTonePosition)
{
    toneKnobPosition = newTonePosition;

    std::cout << "ElectricGuitar::setTone(): Tone knob position is now " << toneKnobPosition << std::endl;
}

void ElectricGuitar::setVolumeGradually(float newVolumePosition)
{
    std::cout << "ElectricGuitar::setVolumeGradually(): Volume knob is starting at " << volumeKnobPosition << std::endl;

    if(newVolumePosition > volumeKnobPosition)
    {
        while(newVolumePosition > volumeKnobPosition)
        {
            volumeKnobPosition += 0.05f;
            std::cout << "Moved volume knob down a bit. Current knob position: " << volumeKnobPosition << std::endl;
        }
    }
    else 
    {
        while(newVolumePosition < volumeKnobPosition)
        {
            volumeKnobPosition -= 0.05f;
            std::cout << "Moved volume knob up a bit. Current knob position: " << volumeKnobPosition << std::endl;
        }
    }
}

void ElectricGuitar::printNeckLength()
{
    std::cout << "This guitar has a neck that is " << this->neckLength << " inches long." << std::endl;
}

void ElectricGuitar::printNumberOfPickups()
{
    std::cout << "This guitar has " << this->numberOfPickups << " pickups." << std::endl;
}

void ElectricGuitar::printNumberOfStrings()
{
    std::cout << "This guitar has " << this->numberOfStrings << " strings." << std::endl;
}

/*
 new UDT 4:
 */
struct PetStore
{
    Chameleon cham1;
    Chameleon cham2;
    Chameleon cham3;
    Chameleon cham4;

    PetStore();
    ~PetStore();

    JUCE_LEAK_DETECTOR(PetStore)
};

struct PetStoreWrapper
{
    PetStore* store = nullptr;

    PetStoreWrapper(PetStore* petStore) :
    store(petStore)
    {

    }
    ~PetStoreWrapper()
    {
        delete store;
    }
};

PetStore::PetStore()
{
    std::cout << "<PetStore> created" << std::endl;
}

PetStore::~PetStore()
{
    cham1.changeColor(255, 0, 0);
    cham2.changeColor(0, 255, 0);
    cham3.changeColor(0, 0, 255);
    cham4.changeColor(255, 255, 255);
}

/*
 new UDT 5:
 */
struct MusicStoreFastFoodCombo
{
    FastFoodRestaurant foodJoint;
    ElectricGuitar guitar1;
    ElectricGuitar guitar2;
    ElectricGuitar guitar3;
    ElectricGuitar guitar4;

    MusicStoreFastFoodCombo();
    ~MusicStoreFastFoodCombo();

    JUCE_LEAK_DETECTOR(MusicStoreFastFoodCombo)
};

struct MusicStoreFastFoodComboWrapper
{
    MusicStoreFastFoodCombo* store = nullptr;

    MusicStoreFastFoodComboWrapper(MusicStoreFastFoodCombo* msffc) :
    store(msffc)
    {

    }
    ~MusicStoreFastFoodComboWrapper()
    {
        delete store;
    }
};

MusicStoreFastFoodCombo::MusicStoreFastFoodCombo()
{
    std::cout << "<MusicStoreFastFoodCombo> created" << std::endl;
}

MusicStoreFastFoodCombo::~MusicStoreFastFoodCombo()
{
    std::cout << "<MusicStoreFastFoodCombo> is closing down" << std::endl;
}

int main()
{
    /*
    Chameleon cham;
    cham.changeColor(100, 140, 50);
    std::cout << "This Chameleon just ran " << cham.run(15.0f, 60.0) << " units." << std::endl;
    std::cout << "This Chameleon has " << cham.numberOfTeeth << " teeth." << std::endl;
    cham.printNumberOfTeeth();
    std::cout << "This Chameleon has " << cham.numberOfScales << " scales." << std::endl;
    cham.printNumberOfScales();
    std::cout << "This Chameleon weighs " << cham.weight << std::endl;
    cham.printWeight();
    cham.flickTongue(2.5, 3);
    cham.flickTongue(3.0, 5);
    cham.eat(3);
    cham.eat(6);
    std::cout << "This Chameleon weighs " << cham.weight << " after eating" << std::endl;
    cham.printWeight();
    std::cout << std::endl;

    FastFoodRestaurant burgerKing;
    std::cout << "Initial profits: $" << burgerKing.totalProfits << std::endl;
    burgerKing.printTotalProfits();
    burgerKing.makeFries(67);
    burgerKing.makeBurger(28);
    burgerKing.restockSupplies(35, 24);
    std::cout << "This restaurant makes $" << burgerKing.profitPerBurger << " profit per burger." << std::endl;
    burgerKing.printProfitPerBurger();
    std::cout << "This restaurant makes $" << burgerKing.profitPerPotato << " profit per potato." << std::endl;
    burgerKing.printProfitPerPotato();
    burgerKing.calculateProfit();
    std::cout << "Profits after sales: $" << burgerKing.totalProfits << std::endl;
    burgerKing.printTotalProfits();
    std::cout << std::endl;

    ElectricGuitar axe;
    std::cout << "This guitar has a neck that is " << axe.neckLength << " inches long." << std::endl;
    axe.printNeckLength();
    std::cout << "This guitar has " << axe.numberOfPickups << " pickups and " << axe.numberOfStrings << " strings." << std::endl;
    axe.printNumberOfPickups();
    axe.printNumberOfStrings();
    axe.setVolume(0.9f);
    axe.setTone(0.5f);
    axe.outputSound();
    axe.setVolumeGradually(0.3f);
    axe.setVolumeGradually(1.0f);
    std::cout << std::endl;

    PetStore petco;
    MusicStoreFastFoodCombo guitarCenterKFC;
    */

    std::cout << std::endl << "Creating Wrapper Class Instances: " << std::endl <<
        "=================================================================" << 
        std::endl << std::endl;

    ChameleonWrapper chamTwo (new Chameleon());
    std::cout << "Wrapped Chameleon's length: " << chamTwo.chameleon->length << std::endl;


    FastFoodRestaurantWrapper carlsjr (new FastFoodRestaurant());
    std::cout << "Wrapped FastFoodRestaurant's burgers in freezer: " << carlsjr.restaurant->burgersInFreezer << std::endl;

    ElectricGuitarWrapper gibsonSG (new ElectricGuitar());
    std::cout << "Wrapped ElectricGuitar's number of pickups: " << gibsonSG.guitar->numberOfPickups << std::endl;

    PetStoreWrapper petSmart (new PetStore());
    std::cout << "Wrapped PetStore's first chameleon's weight: " << petSmart.store->cham1.weight << std::endl;
    
    MusicStoreFastFoodComboWrapper samAshKFC (new MusicStoreFastFoodCombo());
    std::cout << "Wrapped MusicStoreFastFoodCombo's first guitar's number of strings: " << samAshKFC.store->guitar1.numberOfStrings << std::endl;

    std::cout << "good to go!" << std::endl;
}
