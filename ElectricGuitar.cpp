#include "ElectricGuitar.h"


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
