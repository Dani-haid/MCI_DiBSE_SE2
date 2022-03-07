#include <iostream>
#include "item.h"
#include "character.h"
#include "hero.h"

int main() {
    //std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);
    std::cout << "main ausgabe: " << annina.getHeroName() << " " << annina.getHerohealth() << " " << annina.getHerogold() << std::endl;

    //--------------Tests-----------------------
    //Item item1;
    //item1.initItem("Zange", 50);

    //std::cout << "main ausgabe: " << item1.getItemName() << " " << item1.getItemValue() << " " << item1.getItemValidation() << std::endl;

    Character matthias;
    matthias.initCharacter("Matthias", 2, 200);
    std::cout << "main ausgabe: " << matthias.getCharacterName() << " " << matthias.getCharacterhealth() << " " << matthias.getCharacterhealth() << std::endl;

    matthias.attack(annina);
    std::cout<< "Lebenspunkte " << matthias.getCharacterName() << ": " << matthias.getCharacterhealth() << std::endl;
    std::cout<< "Lebenspunkte " << annina.getHeroName() << ": " << annina.getHerohealth() << std::endl;

/*    annina.attack(peter);
    std::cout<< "Lebenspunkte " << peter.name << ": " << peter.health << std::endl;
    std::cout<< "Lebenspunkte " << annina.name << ": " << annina.health << std::endl;*/





    return 0;
}
