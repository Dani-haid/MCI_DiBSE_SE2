#include <iostream>
#include "hero.h"
#include <ctime>
#include <cstdlib>
#include "character.h"

int main() {
    std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);
    std::cout << "*** " << "Die Heldin " << annina.getName() << " wurde erstellt. Lebenspunkte: " << annina.getHealth() << " Gold: " << annina.getGold() << std::endl;
    Item zaubertrank;
    zaubertrank.initItem("Zaubertrank", 75);
    annina.addInventarItem(zaubertrank);
    Item teddykanone;
    teddykanone.initItem("Teddykanone", 40);
    annina.addInventarItem(teddykanone);

    Character matthias;
    matthias.initCharacter("Matthias", 50, 0);
    std::cout << "*** " << "Der Gegner " << matthias.getName() << " wurde erstellt. Lebenspunkte: " << matthias.getHealth() << " Gold: " << matthias.getGold() << std::endl;
    Item giftpfeil;
    giftpfeil.initItem("Giftpfeil", 55);
    matthias.addInventarItem(giftpfeil);
    Item softwareHarpune;
    softwareHarpune.initItem("Software-Harpune", 355);
    matthias.addInventarItem(softwareHarpune);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 10);
    std::cout << "*** " << "Der Gegner " << pascal.getName() << " wurde erstellt. Lebenspunkte: " << pascal.getHealth() << " Gold: " << pascal.getGold() << std::endl;
    Item taschenrechner;
    taschenrechner.initItem("Taschenrechner", 15);
    pascal.addInventarItem(taschenrechner);


    if(annina.fight(matthias)){
        if(annina.fight(pascal)){
            //Hero verkauft Items
            std::cout << "**** "<< annina.getName() << " geht mit Ihrer Beute zur Bank." << " ****"<< std::endl;
            if(annina.getHealth()>0){
                for (int j = 0; j < HERO_INVENTORY_SIZE; ++j) {
                    annina.sellItem(j);
                }
            }
        }else{
            std::cout<<"Game Over! " << annina.getName() << " fiel in Ohnmacht! "<< pascal.getName() << " hat noch " << pascal.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        }
    }else{
        std::cout<<"Game Over! " << annina.getName() << " fiel in Ohnmacht! "<< matthias.getName() << " hat noch " << matthias.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
    }


    return 0;
}
