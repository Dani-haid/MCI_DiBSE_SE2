#include <iostream>
#include "hero.h"
#include <ctime>
#include <cstdlib>
#include "character.h"

int main() {
    //std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);
    std::cout << "main ausgabe: " << annina.getName() << " " << annina.getHealth() << " " << annina.getGold() << std::endl;
    //wie lege ich hier ein neues Inventory an -> Zusatzfunktion von Angabe ggf.
    //this->inventory[i].initItem();

    //--------------Tests-----------------------
    //Item item1;
    //item1.initItem("Zange", 50);

    //std::cout << "main ausgabe: " << item1.getItemName() << " " << item1.getItemValue() << " " << item1.getItemValidation() << std::endl;

    Character matthias;
    matthias.initCharacter("Matthias", 2, 200);
    std::cout << "main ausgabe: " << matthias.getName() << " " << matthias.getHealth() << " " << matthias.getHealth() << std::endl;

    Character pascal;
    pascal.initCharacter("Pascal", 100, 10);
    std::cout << "main ausgabe: " << pascal.getName() << " " << pascal.getHealth() << " " << pascal.getHealth() << std::endl;

    matthias.attack(annina);
    std::cout<< "Lebenspunkte " << matthias.getName() << ": " << matthias.getHealth() << std::endl;
    std::cout<< "Lebenspunkte " << annina.getName() << ": " << annina.getHealth() << std::endl;


    annina.attack(matthias);
    std::cout<< "Lebenspunkte " << matthias.getName() << ": " << matthias.getHealth() << std::endl;
    std::cout<< "Lebenspunkte " << annina.getName() << ": " << annina.getHealth() << std::endl;



    return 0;
}
