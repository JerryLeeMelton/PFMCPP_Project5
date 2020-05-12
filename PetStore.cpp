#include "PetStore.h"

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
