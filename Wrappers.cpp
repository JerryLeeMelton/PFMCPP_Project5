#include "Chameleon.h"
#include "FastFoodRestaurant.h"
#include "ElectricGuitar.h"
#include "PetStore.h"
#include "MusicStoreFastFoodCombo.h"
#include "Wrappers.h"

ChameleonWrapper::ChameleonWrapper(Chameleon* c) : 
chameleon(c)
{

}
ChameleonWrapper::~ChameleonWrapper()
{
    delete chameleon;
}


FastFoodRestaurantWrapper::FastFoodRestaurantWrapper(FastFoodRestaurant* ffr) :
restaurant(ffr)
{

}
FastFoodRestaurantWrapper::~FastFoodRestaurantWrapper()
{
    delete restaurant;
}


ElectricGuitarWrapper::ElectricGuitarWrapper(ElectricGuitar* gtr) :
guitar(gtr)
{

}
ElectricGuitarWrapper::~ElectricGuitarWrapper()
{
    delete guitar;
}


PetStoreWrapper::PetStoreWrapper(PetStore* petStore) :
store(petStore)
{

}
PetStoreWrapper::~PetStoreWrapper()
{
    delete store;
}


MusicStoreFastFoodComboWrapper::MusicStoreFastFoodComboWrapper(MusicStoreFastFoodCombo* msffc) :
store(msffc)
{

}
MusicStoreFastFoodComboWrapper::~MusicStoreFastFoodComboWrapper()
{
    delete store;
}
