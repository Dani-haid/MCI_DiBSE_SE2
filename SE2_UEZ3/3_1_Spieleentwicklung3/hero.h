#ifndef INC_2_1_SPIELEENTWICKUNG2_HERO_H
#define INC_2_1_SPIELEENTWICKUNG2_HERO_H

#include <string>
#include "item.h"
#include "character.h"

#define HERO_EQUIPMENT_SIZE			2

//Forward declaration
//class NPC;

class Hero : public Character{
protected:
    Item equipment[HERO_EQUIPMENT_SIZE];

public:
    //Konstruktor
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
    : Character(name, health, gold, armor, magicResistance){
            std::cout << "Calling Hero::Constructor" << std::endl;
    };

    //Destruktor
    virtual ~Hero() {
        std::cout << "Calling Hero::Destructor" << std::endl;
    }

    virtual void attack(Character &enemy) override;

    //void attack(Character &enemy);
    //bool fight(Character &enemy);

    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);

    //int stealRandomItem(Character &enemy);

    void sellItem(int index);

    //Getter:
    Item *getEquipment(int index);
};


#endif //INC_2_1_SPIELEENTWICKUNG2_HERO_H
