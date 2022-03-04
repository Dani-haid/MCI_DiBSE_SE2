#include <iostream>
#include "item.h"
#include "character.h"
#include "hero.h"

int main() {
    //std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);
    //std::cout << "main ausgabe: " << annina.name << " " << annina.health << " " << annina.gold << std::endl;

    //--------------Tests-----------------------
    //Item item1;
    //item1.initItem("Zange", 50);

    //std::cout << "main ausgabe: " << item1.name << " " << item1.value << " " << item1.isValid << std::endl;

    Character peter;
    peter.initCharacter("Peter", 2, 200);

    peter.attack(annina);
    std::cout<< "Lebenspunkte " << peter.name << ": " << peter.health << std::endl;
    std::cout<< "Lebenspunkte " << annina.name << ": " << annina.health << std::endl;

/*    annina.attack(peter);
    std::cout<< "Lebenspunkte " << peter.name << ": " << peter.health << std::endl;
    std::cout<< "Lebenspunkte " << annina.name << ": " << annina.health << std::endl;*/





    return 0;
}
