#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"
#include "FastFoodRestaurant.h"
#include "ElectricGuitar.h"

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
