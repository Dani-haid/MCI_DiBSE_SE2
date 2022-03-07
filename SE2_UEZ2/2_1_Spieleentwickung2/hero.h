#ifndef INC_2_1_SPIELEENTWICKUNG2_HERO_H
#define INC_2_1_SPIELEENTWICKUNG2_HERO_H

#include <iostream>
#include "item.h"
//#include "character.h"
#include <string>

class Character;

class Hero {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    Item equipment[2];

public:
    void initHero(const std::string& name, int health, int gold);

    //void attack(Character &enemy);

    //Getter:
    std::string getHeroName() {
        return name;
    };
    int getHerohealth() {
        return health;
    };
    int getHerogold() {
        return gold;
    };


    void reduceHeroHealth(int damage) {
        this->health -= damage;
    };
    //Setter:

};


#endif //INC_2_1_SPIELEENTWICKUNG2_HERO_H
