/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>
#include "LeakedObjectDetector.h"

#include "Chameleon.h"
#include "FastFoodRestaurant.h"
#include "ElectricGuitar.h"
#include "PetStore.h"
#include "MusicStoreFastFoodCombo.h"
#include "Wrappers.h"

int main()
{
    ChameleonWrapper cham(new Chameleon());
    cham.chameleon->changeColor(100, 140, 50);
    std::cout << "This Chameleon just ran " << cham.chameleon->run(15.0f, 60.0) << " units." << std::endl;
    std::cout << "This Chameleon has " << cham.chameleon->numberOfTeeth << " teeth." << std::endl;
    cham.chameleon->printNumberOfTeeth();
    std::cout << "This Chameleon has " << cham.chameleon->numberOfScales << " scales." << std::endl;
    cham.chameleon->printNumberOfScales();
    std::cout << "This Chameleon weighs " << cham.chameleon->weight << std::endl;
    cham.chameleon->printWeight();
    cham.chameleon->flickTongue(2.5, 3);
    cham.chameleon->flickTongue(3.0, 5);
    cham.chameleon->eat(3);
    cham.chameleon->eat(6);
    std::cout << "This Chameleon weighs " << cham.chameleon->weight << " after eating" << std::endl;
    cham.chameleon->printWeight();
    std::cout << std::endl;

    FastFoodRestaurantWrapper burgerKing(new FastFoodRestaurant());
    std::cout << "Initial profits: $" << burgerKing.restaurant->totalProfits << std::endl;
    burgerKing.restaurant->printTotalProfits();
    burgerKing.restaurant->makeFries(67);
    burgerKing.restaurant->makeBurger(28);
    burgerKing.restaurant->restockSupplies(35, 24);
    std::cout << "This restaurant makes $" << burgerKing.restaurant->profitPerBurger << " profit per burger." << std::endl;
    burgerKing.restaurant->printProfitPerBurger();
    std::cout << "This restaurant makes $" << burgerKing.restaurant->profitPerPotato << " profit per potato." << std::endl;
    burgerKing.restaurant->printProfitPerPotato();
    burgerKing.restaurant->calculateProfit();
    std::cout << "Profits after sales: $" << burgerKing.restaurant->totalProfits << std::endl;
    burgerKing.restaurant->printTotalProfits();
    std::cout << std::endl;

    ElectricGuitarWrapper axe(new ElectricGuitar());
    std::cout << "This guitar has a neck that is " << axe.guitar->neckLength << " inches long." << std::endl;
    axe.guitar->printNeckLength();
    std::cout << "This guitar has " << axe.guitar->numberOfPickups << " pickups and " << axe.guitar->numberOfStrings << " strings." << std::endl;
    axe.guitar->printNumberOfPickups();
    axe.guitar->printNumberOfStrings();
    axe.guitar->setVolume(0.9f);
    axe.guitar->setTone(0.5f);
    axe.guitar->outputSound();
    axe.guitar->setVolumeGradually(0.3f);
    axe.guitar->setVolumeGradually(1.0f);
    std::cout << std::endl;

    PetStoreWrapper petco(new PetStore());
    MusicStoreFastFoodComboWrapper guitarCenterKFC(new MusicStoreFastFoodCombo());

    std::cout << "good to go!" << std::endl;
}
