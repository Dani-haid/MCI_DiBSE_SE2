#ifndef INC_2_1_SPIELEENTWICKUNG2_HERO_H
#define INC_2_1_SPIELEENTWICKUNG2_HERO_H

#include <string>
#include "item.h"
#include "character.h"

#define HERO_EQUIPMENT_SIZE			2

class Hero : public Character{
protected:
    Item equipment[HERO_EQUIPMENT_SIZE];

public:
    //Konstruktor
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
    : Character(name, health, gold, armor, magicResistance){
        std::cout << "Held " << this->getName() << ", " << this->getHealth() << " Lebenspunkte, "
                  << this->getGold() << " Gold, " << this->getArmor() << " Armor, "
                  << this->getMagicResistance() << " Magic Resistance" << " wurde erstellt." << std::endl;
    };

    //Destruktor
    virtual ~Hero() {
        std::cout << "Heldin " << *this << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
    }

    virtual void attack(Character &enemy) override;

    bool fight(Character &enemy);

    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);

    void sellItem(int index);
    Item retrieveRandomLoot(Character &enemy);

    //Getter:
    Item *getEquipment(int index);

};

std::ostream &operator<<(std::ostream& out, const Hero &h);


#endif //INC_2_1_SPIELEENTWICKUNG2_HERO_H
