#ifndef INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H
#define INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H

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
    //Konstruktor:
    Character(const std::string& name, int health, int gold, int armor, int magicResistance)
    : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance){};

    //Destruktor:
    virtual ~Character(){};

    virtual void attack(Character &hero) = 0;

    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

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

std::ostream &operator<<(std::ostream &out, const Character &c);


#endif //INC_3_1_SPIELEENTWICKLUNG3_CHARACTER_H
