#ifndef INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H
#define INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H

#include <iostream>
#include "item.h"
#include <string>
#include "hero.h"

//class Hero; --> CHECK!

class Character {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];

public:
    void initCharacter(const std::string& name, int health, int gold);

    void attack(Hero &hero);
    //wieso hier Pointer oder Referenz??

    //Getter:
    std::string getCharacterName() {
        return name;
    };
    int getCharacterhealth() {
        return health;
    };
    int getCharactergold() {
        return gold;
    };
    void getInventory(int index) {
        //return ??
        //tbd!!
    };

    //Setter tbd!
    //CHECK
    void reduceCharacterHealth(int damage) {
        this->health -= damage;
    };
/*    void setCharacterhealth(int health) {
        this->health = health;
    };*/
};


#endif //INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H
