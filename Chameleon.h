#pragma once

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

        Color();

        void setColor(int newRedValue, int newGreenValue, int newBlueValue);
        void setAlpha(int newAlphaValue);

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
