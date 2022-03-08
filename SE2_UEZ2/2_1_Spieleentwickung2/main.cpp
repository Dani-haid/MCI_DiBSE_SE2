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

    Item item1;
    item1.initItem("Zaubertrank", 75);
    annina.addInventarItem(item1);

    Character matthias;
    matthias.initCharacter("Matthias", 50, 0);
    std::cout << "*** " << "Der Gegner " << matthias.getName() << " wurde erstellt. Lebenspunkte: " << matthias.getHealth() << " Gold: " << matthias.getGold() << std::endl;

    Item item2;
    item2.initItem("Giftpfeil", 55);
    matthias.addInventarItem(item2);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 10);
    std::cout << "*** " << "Der Gegner " << pascal.getName() << " wurde erstellt. Lebenspunkte: " << pascal.getHealth() << " Gold: " << pascal.getGold() << std::endl;

    Item item3;
    item3.initItem("Taschenrechner", 15);
    pascal.addInventarItem(item3);


    if(annina.fight(matthias)){
        std::cout<<matthias.getName() << " fiel in Ohnmacht! "<< annina.getName() << " hat noch " << annina.getHealth() << " Lebenspunkte uebrig!" <<std::endl;

        int random = (std::rand() % 10 + 1)-1;
        int count = 1;
        while(1){
            //std::cout << "Random Number: "<< random << std:: endl;
            Item *foundItem = matthias.removeInventarItem(random);
            if(!foundItem){
                if(count >= 20){
                    std::cout << "keine Items im Inventar von "<< matthias.getName() <<" gefunden." << std:: endl;
                    break;
                }
                random = (std::rand() % 10 + 1)-1;
                count ++;
                continue;
            };
            //std::cout << "Item "<< foundItem->getName() << " an Stelle " << random <<" im Inventar von "<< matthias.getName() <<" gefunden." << std:: endl;
            if(annina.addInventarItem(*foundItem) <= -1){
                std::cout<<"Kein Platz mehr vorhanden! Inventar von " << annina.getName() <<" ist voll."<<std::endl;
                break;
            };
            break;
        }
    }else{
        std::cout<<"Game Over! " << annina.getName() << " fiel in Ohnmacht! "<< matthias.getName() << " hat noch " << matthias.getName() << " Lebenspunkte uebrig!" <<std::endl;
        return 0;
    }

    if(annina.fight(pascal)){
        std::cout<<pascal.getName() << " fiel in Ohnmacht! "<< annina.getName() << " hat noch " << annina.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        int random = (std::rand() % 10 + 1)-1;
        int count = 1;
        while(1){
            //std::cout << "Random Number: "<< random << std:: endl;
            Item *foundItem = pascal.removeInventarItem(random);
            if(!foundItem){
                if(count >= 20){
                    std::cout << "keine Items im Inventar von "<< pascal.getName() <<" gefunden." << std:: endl;
                    break;
                }
                random = (std::rand() % 10 + 1)-1;
                count ++;
                continue;
            };
            //std::cout << "Item "<< foundItem->getName() << " an Stelle " << random <<" im Inventar von "<< matthias.getName() <<" gefunden." << std:: endl;
            if(annina.addInventarItem(*foundItem) <= -1){
                std::cout<<"Kein Platz mehr vorhanden! Inventar von " << annina.getName() <<" ist voll."<<std::endl;
                break;
            };
            break;
        }
    }else{
        std::cout<<"Game Over! " << annina.getName() << " fiel in Ohnmacht! "<< pascal.getName() << " hat noch " << pascal.getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        return 0;
    }

    for (int j = 0; j<10; ++j) {
        if(annina.getInventory(j)){
            annina.sellItem(j);
        }
    }



    return 0;
}
