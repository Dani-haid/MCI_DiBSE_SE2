#ifndef INC_2_1_SPIELEENTWICKUNG2_HERO_H
#define INC_2_1_SPIELEENTWICKUNG2_HERO_H

#include <iostream>
#include "item.h"
//#include "character.h"
#include <string>

class Character;

class Hero {
public:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    Item equipment[2];

public:
    void initHero(std::string name, int health, int gold){
        this->name = name;
        this->health = health;
        this->gold = gold;

        std::cout << this->name << " " << this->health << " " << this->gold << std::endl;

        for (int i = 0; i < 10; ++i) {
            Item inventory[i];
            inventory[i].initItem();
        }

        for (int i = 0; i < 2; ++i) {
            Item equipment[i];
            equipment[i].initItem();
        }
    };

    void attack(Character &enemy){
        //Heldin greift Gegener an und reduziert health random zwischen 15-25
        int damage = 15 + std::rand() % 11;
        enemy.health -= damage;
        std::cout<< name << " trifft " << enemy.name << " für " << damage << " Lebenspunkte!" << std::endl;
    };

};


#endif //INC_2_1_SPIELEENTWICKUNG2_HERO_H
