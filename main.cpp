 #include <iostream>
 /*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 copied UDT 1:
 */
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
    Chameleon cham;
    cham.changeColor(100, 140, 50);
    std::cout << "This Chameleon just ran " << cham.run(15.0f, 60.0) << " units." << std::endl;
    std::cout << "This Chameleon has " << cham.numberOfTeeth << " teeth." << std::endl;
    std::cout << "This Chameleon has " << cham.numberOfScales << " scales." << std::endl;
    std::cout << "This Chameleon weighs " << cham.weight << std::endl;
    cham.flickTongue(2.5, 3);
    cham.flickTongue(3.0, 5);
    cham.eat(3);
    cham.eat(6);
    std::cout << "This Chameleon weighs " << cham.weight << " after eating" << std::endl;
    std::cout << std::endl;

    FastFoodRestaurant burgerKing;
    std::cout << "Initial profits: $" << burgerKing.totalProfits << std::endl;
    burgerKing.makeFries(67);
    burgerKing.makeBurger(28);
    burgerKing.restockSupplies(35, 24);
    std::cout << "This restaurant makes $" << burgerKing.profitPerBurger << " profit per burger." << std::endl;
    std::cout << "This restaurant makes $" << burgerKing.profitPerPotato << " profit per potato." << std::endl;
    burgerKing.calculateProfit();
    std::cout << "Profits after sales: $" << burgerKing.totalProfits << std::endl;
    std::cout << std::endl;

    ElectricGuitar axe;
    std::cout << "This guitar has a neck that is " << axe.neckLength << " inches long." << std::endl;
    std::cout << "This guitar has " << axe.numberOfPickups << " pickups and " << axe.numberOfStrings << " strings." << std::endl;
    axe.setVolume(0.9f);
    axe.setTone(0.5f);
    axe.outputSound();
    axe.setVolumeGradually(0.3f);
    axe.setVolumeGradually(1.0f);
    std::cout << std::endl;

    PetStore petco;
    MusicStoreFastFoodCombo guitarCenterKFC;

    std::cout << "good to go!" << std::endl;
}
