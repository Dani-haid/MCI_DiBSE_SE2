#include <iostream>
#include "character.h"
#include "hero.h"
#include "npc.h"
#include "fighter.h"
#include "sorcerer.h"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina("Annina", 300, 50, 5, 3);
    annina.addInventarItem(Item("Zaubertrank", 75));
    annina.addInventarItem(Item("Teddykanone", 40));
    //wieso bekommt dieses Item hier keinen Namen?
    //wann wird nochmal "new" verwendet?


    NPC matthias("Matthias", 50, 0, 10, 5);
    matthias.addInventarItem(Item("Giftpfeil", 55));
    matthias.addInventarItem(Item("Software-Harpune", 355));

    NPC pascal("Pascal", 100, 10, 22, 30);
    pascal.addInventarItem(Item("Taschenrechner", 15));

    Fighter dani("Dani", 200, 10, 22, 30, 4);
    dani.addInventarItem(Item("Schwert", 45));
    Sorcerer chris("Chris", 200, 10, 22, 30, 4);
    chris.addInventarItem(Item("Laser", 67));


    return 0;
}
