#include <iostream>
#include "hero.h"
#include <ctime>
#include <cstdlib>

int main() {

    std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero_t annina;
    initHero(&annina, (char*)"Annina", 300, 50);
    initItem(&annina.inventory[0], (char*)"Machete", 35);
    initItem(&annina.inventory[1], (char*)"Zaubertrank", 75);

    Character_t matthias;
    initCharacter(&matthias, (char*)"Matthias", 50, 0);
    initItem(&matthias.inventory[0], (char*)"Angelhaken", 15);

    Character_t pascal;
    initCharacter(&pascal, (char*)"Pascal", 100, 10);
    initItem(&pascal.inventory[0], (char*)"Giftpfeil", 5);

    if(fight(&annina, &matthias)){
        for (int i = 0; i < 12; ++i) {
            if(annina.inventory[i].isValid == true){
                if(i >= 11){
                    std::cout<<"Inventar ist voll."<<std::endl;
                }
                continue;
            }else{
                annina.inventory[i].name = "Zeitmaschine";
                annina.inventory[i].value = 25;
                annina.inventory[i].isValid = true;
                std::cout<<"Gegenstand " << annina.inventory[i].name << " wurde zum Inventar der Heldin hinzugefügt."<<std::endl;
                break;
            }
        }
        if(fight(&annina, &pascal)){
            for (int i = 0; i < 12; ++i) {
                if(annina.inventory[i].isValid == true){
                    if(i >= 11){
                        std::cout<<"Inventar ist voll."<<std::endl;
                    }
                    continue;
                }else{
                    annina.inventory[i].name = "Laserschwert";
                    annina.inventory[i].value = 25;
                    annina.inventory[i].isValid = true;
                    std::cout<<"Gegenstand " <<annina.inventory[i].name << " wurde zum Inventar der Heldin hinzugefügt."<<std::endl;
                    break;
                }
            }
            for (int j = 0; j<12; ++j) {
                if(annina.inventory[j].isValid == true){
                    sellItem(&annina, j);
                }
            }
        };
    };
    return 0;
}
