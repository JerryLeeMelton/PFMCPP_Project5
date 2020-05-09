#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

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
