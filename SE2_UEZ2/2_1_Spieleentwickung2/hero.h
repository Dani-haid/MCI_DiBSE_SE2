#ifndef INC_2_1_SPIELEENTWICKUNG2_HERO_H
#define INC_2_1_SPIELEENTWICKUNG2_HERO_H

#include <string>
#include "item.h"

#define HERO_INVENTORY_SIZE		10
#define HERO_EQUIPMENT_SIZE			2

//Forward declaration
class Character;

class Hero {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[HERO_INVENTORY_SIZE];
    Item equipment[HERO_EQUIPMENT_SIZE];

public:
    void initHero(const std::string& name, int health, int gold);
    void attack(Character &enemy);

    void sellItem(int index);
    bool fight(Character &enemy);

    int addInventarItem(const Item& item);
    int addEquipmentItem(const Item& item);
    Item removeInventarItem(int slot);
    Item removeEquipmentItem(int slot);
    int stealRandomItem(Character &enemy);

    //Getter:
    const std::string& getName() const;
    int getHealth() const;
    int getGold() const;
    Item *getInventory(int index);
    Item *getEquipment(int index);

    //Setter:
    void setName(const std::string &name);
    void setHealth(int health);
    void setGold(int gold);
};


#endif //INC_2_1_SPIELEENTWICKUNG2_HERO_H
