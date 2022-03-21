#include <iostream>
#include "character.h"
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina("Annina", 300, 50, 5, 3);
    annina.addInventarItem(Item("Zaubertrank", 75));
    annina.addInventarItem(Item("Teddykanone", 40));

    Fighter matthias("Matthias", 50, 10, 14, 30, 4);
    matthias.addInventarItem(Item("Schwert", 45));
    Sorcerer pascal("Pascal", 100, 10, 3, 30, 4);
    pascal.addInventarItem(Item("Laser", 67));


    Character &enemy = matthias;
    if(annina.fight(matthias)){
        if(annina.fight(pascal)){
            //Hero verkauft Items
            std::cout << "**** "<< annina.getName() << " geht mit Ihrer Beute zur Bank." << " ****"<< std::endl;
            if(annina.getHealth()>0){
                for (int j = 0; j < CHARACTER_INVENTORY_SIZE; ++j) {
                    annina.sellItem(j);
                }
            }
            return 0;
        }
        enemy = pascal;
    }
    std::cout<<"Game Over! " << annina << " fiel in Ohnmacht! "<<  enemy << " hat noch " << enemy.getHealth() << " Lebenspunkte uebrig!" <<std::endl;


    return 0;
}
