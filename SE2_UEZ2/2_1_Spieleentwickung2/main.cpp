#include <iostream>
#include "hero.h"
#include <ctime>
#include <cstdlib>
#include "character.h"

int main() {
    //std::srand(std::time(nullptr));//damit rand() immer unterschiedlich ist

    Hero annina;
    annina.initHero("Annina", 300, 50);
    std::cout << "Init Hero: " << annina.getName() << " " << annina.getHealth() << " " << annina.getGold() << std::endl;



    Item item1;
    item1.initItem("Zaubertrank", 75);
    annina.addInventarItem(item1);

    //std::cout << annina.getInventory(0)->isIsValid()<< std::endl;
    //std::cout << annina.getInventory(0)<< std::endl;
    //std::cout << annina.getInventory(3)->isIsValid()<< std::endl;


    Character matthias;
    matthias.initCharacter("Matthias", 100, 200);
    std::cout << "Init Enemy1: " << matthias.getName() << " " << matthias.getHealth() << " " << matthias.getGold() << std::endl;

    Item item2;
    item1.initItem("Giftpfeil", 55);
    matthias.addInventarItem(item2);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 10);
    std::cout << "Init Enemy2: " << pascal.getName() << " " << pascal.getHealth() << " " << pascal.getHealth() << std::endl;

    /*matthias.attack(annina);
    std::cout<< "Lebenspunkte " << matthias.getName() << ": " << matthias.getHealth() << std::endl;
    std::cout<< "Lebenspunkte " << annina.getName() << ": " << annina.getHealth() << std::endl;*/


    if(annina.fight(matthias)){
        std::cout<<matthias.getName() << " fiel in Ohnmacht! "<< annina.getName() << " hat noch " << annina.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        //Es wird ein zufälliger Gegenstand aus dem Inventar des Charakters in das Inventar der Heldin übertragen:
        int rand;


        /*while(1){
            rand = std::rand() % 10;
            if(matthias.removeInventarItem(rand)){
                Item* item = matthias.removeInventarItem(rand);
                annina.addInventarItem(*item);
                break;
            }
        }


        for (int i = 0; i < 10; ++i) {
            if(annina.getInventory(i)->isIsValid()){
                if(i >= 9){
                    std::cout<<"Inventar ist voll."<<std::endl;
                }
                continue;
            }else{
                annina.getInventory(i)->setName("Zeitmaschine");
                annina.getInventory(i)->setValue(25);
                annina.getInventory(i)->setIsValid(true);
                std::cout<<"Gegenstand " << annina.getInventory(i)->getName() << " wurde zum Inventar der Heldin hinzugefügt."<<std::endl;
                break;
            }
        }*/
    }
         else{
        std::cout<<"Game Over! " << annina.getName() << " fiel in Ohnmacht! "<< matthias.getName() << " hat noch " << matthias.getName() << " Lebenspunkte uebrig!" <<std::endl;
        return 0;
    }

    if(annina.fight(pascal)){
        std::cout<<pascal.getName() << " fiel in Ohnmacht! "<< annina.getName() << " hat noch " << annina.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        /*for (int i = 0; i < 10; ++i) {
            if(annina.getInventory(i)->isIsValid()){
                if(i >= 9){
                    std::cout<<"Inventar ist voll."<<std::endl;
                }
                continue;
            }else{
                annina.getInventory(i)->setName("Laserschwert");
                annina.getInventory(i)->setValue(15);
                annina.getInventory(i)->setIsValid(true);
                std::cout<<"Gegenstand " << annina.getInventory(i)->getName() << " wurde zum Inventar der Heldin hinzugefügt."<<std::endl;
                break;
            }
        }*/
    }else{
        std::cout<<"Game Over! " << annina.getName() << " fiel in Ohnmacht! "<< matthias.getName() << " hat noch " << matthias.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        return 0;
    }



    return 0;
}
