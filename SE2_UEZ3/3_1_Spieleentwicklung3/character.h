#ifndef INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H
#define INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H

#include <iostream>
#include <string>
#include "item.h"

#define CHARACTER_INVENTORY_SIZE	10

class Character {
protected:
    std::string name;
    int health;
    int gold;
    Item inventory[CHARACTER_INVENTORY_SIZE];
    int armor;
    int magicResistance;

public:

    //Default Konstruktor:
    Character() : name(""), health(0), gold(0), armor(0), magicResistance(0){}
    //Konstruktor:
    Character(std::string name, int health, int gold, int armor, int magicResistance) : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){}
    //Destruktor:
    ~Character();


    void attack(Hero &hero); //dynamisch: in Hero & NPC überlagern

    int addInventarItem(const Item& item);//noch definieren
    Item removeInventarItem(int slot);//noch definieren


    //Getter:
    const std::string& getName() const;
    int getHealth() const;
    int getGold() const;
    Item* getInventory(int index);
    int getArmor() const;
    int getMagicResistance() const;

    //Setter:
    void setName(const std::string& name);
    void setHealth(int health);
    void setGold(int gold);
    void setArmor(int armor);
    void setMagicResistance(int magicResistance);

};


#endif //INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H
