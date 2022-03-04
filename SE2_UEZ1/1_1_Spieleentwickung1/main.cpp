#include <iostream>
#include "hero.h"
#include <ctime>
#include <cstdlib>
#include "character.h"

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
        std::cout<<matthias.name << " fiel in Ohnmacht! "<< annina.name << " hat noch " << annina.health << " Lebenspunkte uebrig!" <<std::endl;
        for (int i = 0; i < 10; ++i) {
            if(annina.inventory[i].isValid == true){
                if(i >= 9){
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
    }else{
        std::cout<<"Game Over! " << annina.name << " fiel in Ohnmacht! "<< matthias.name << " hat noch " << matthias.health << " Lebenspunkte uebrig!" <<std::endl;
        return 0;
    }

    if(fight(&annina, &pascal)){
        std::cout<<pascal.name << " fiel in Ohnmacht! "<< annina.name << " hat noch " << annina.health << " Lebenspunkte uebrig!" <<std::endl;
        for (int i = 0; i < 10; ++i) {
            if(annina.inventory[i].isValid == true){
                if(i >= 9){
                    std::cout<<"Inventar ist voll."<<std::endl;
                }
                continue;
            }else{
                annina.inventory[i].name = "Laserschwert";
                annina.inventory[i].value = 15;
                annina.inventory[i].isValid = true;
                std::cout<<"Gegenstand " << annina.inventory[i].name << " wurde zum Inventar der Heldin hinzugefügt."<<std::endl;
                break;
            }
        }
    }else{
        std::cout<<"Game Over! " << annina.name << " fiel in Ohnmacht! "<< matthias.name << " hat noch " << matthias.health << " Lebenspunkte uebrig!" <<std::endl;
        return 0;
    }

    for (int j = 0; j<10; ++j) {
        if(annina.inventory[j].isValid == true){
            sellItem(&annina, j);
        }
    }

    return 0;
}
