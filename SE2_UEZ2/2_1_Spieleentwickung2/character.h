#ifndef INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H
#define INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H

#include <string>
#include "item.h"

#define CHARACTER_INVENTORY_SIZE	10

//Forward declaration
class Hero;

class Character {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[CHARACTER_INVENTORY_SIZE];

public:
    void initCharacter(const std::string& name, int health, int gold);
    void attack(Hero &hero);

    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);


    //Getter:
    const std::string& getName() const;
    int getHealth() const;
    int getGold() const;
    Item* getInventory(int index);

    //Setter:
    void setName(const std::string& name);
    void setHealth(int health);
    void setGold(int gold);
};


#endif //INC_2_1_SPIELEENTWICKUNG2_CHARACTER_H
