#ifndef INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H
#define INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H

#include <iostream>
#include "item.h"
#include <string>
//#include "hero.h"

class Hero;

class Character {
public:
    std::string name;
    int health;
    int gold;
    Item inventory[10];

public:
    void initCharacter(std::string name, int health, int gold){
        this->name = name;
        this->health = health;
        this->gold = gold;

        for (int i = 0; i < 10; ++i) {
            Item inventory[i];
            inventory[i].initItem(); //stimmt das hier?
        }
    };

    void attack(Hero &hero){
        //Gegner greift Heldin an und reduziert health random zwischen 5-15
        int damage = 5 + std::rand() % 11;
        hero.health -= damage;//geht nur wenn health in Hero auf public ist, wenn geändert dann über setter setzen!
        std::cout<< name << " trifft " << hero.name << " für " << damage << " Lebenspunkte!" << std::endl;
    };
};


#endif //INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H
