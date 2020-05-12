#pragma once

#include "LeakedObjectDetector.h"
#include "Chameleon.h"

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
