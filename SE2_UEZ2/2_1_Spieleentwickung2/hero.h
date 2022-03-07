#ifndef INC_2_1_SPIELEENTWICKUNG2_HERO_H
#define INC_2_1_SPIELEENTWICKUNG2_HERO_H

#include <string>
#include "item.h"

//Forward declaration
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
    void attack(Character &enemy);

    void sellItem(int index);
    bool fight(Character &enemy);

    int addInventarItem(const Item& item);
    int addEquipmentItem(const Item& item);
    Item* removeInventarItem(int slot);
    Item* removeEquipmentItem(int slot);

    //Getter:
    std::string getName();
    int getHealth();
    int getGold();
    Item *getInventory(int index);
    Item *getEquipment(int index);

    //Setter:
    void setHealth(int health);
    void setGold(int gold);
};


#endif //INC_2_1_SPIELEENTWICKUNG2_HERO_H
