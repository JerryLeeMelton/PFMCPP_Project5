struct Chameleon;
struct FastFoodRestaurant;
struct ElectricGuitar;
struct PetStore;
struct MusicStoreFastFoodCombo;

struct ChameleonWrapper
{
    Chameleon* chameleon = nullptr;

    ChameleonWrapper(Chameleon* c);
    ~ChameleonWrapper();
};

struct FastFoodRestaurantWrapper
{
    FastFoodRestaurant* restaurant = nullptr;

    FastFoodRestaurantWrapper(FastFoodRestaurant* ffr);
    ~FastFoodRestaurantWrapper();
};

struct ElectricGuitarWrapper
{
    ElectricGuitar* guitar = nullptr;

    ElectricGuitarWrapper(ElectricGuitar* gtr);
    ~ElectricGuitarWrapper();
};

struct PetStoreWrapper
{
    PetStore* store = nullptr;

    PetStoreWrapper(PetStore* petStore);
    ~PetStoreWrapper();
};

struct MusicStoreFastFoodComboWrapper
{
    MusicStoreFastFoodCombo* store = nullptr;

    MusicStoreFastFoodComboWrapper(MusicStoreFastFoodCombo* msffc);
    ~MusicStoreFastFoodComboWrapper();
};
