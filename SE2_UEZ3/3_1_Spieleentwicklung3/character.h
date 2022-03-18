#ifndef INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H
#define INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H

#include <iostream>
#include <string>
#include "item.h"

class Character {
protected:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    int armor;
    int magicResistance;

public:

    //-----------Wie initalisiert man hier Array mit Objekten???----------

    //Default Konstruktor:
    Character() : name(""), health(0), gold(0), armor(0), magicResistance(0){}
    //Konstruktor:
    Character(std::string name, int health, int gold, int armor, int magicResistance) : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){}
    //Destruktor:
    ~Character();
};


#endif //INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H
