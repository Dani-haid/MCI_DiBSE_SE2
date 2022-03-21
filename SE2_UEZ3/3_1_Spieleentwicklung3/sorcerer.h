#ifndef INC_3_1_SPIELEENTWICKLUNG3_SORCERER_H
#define INC_3_1_SPIELEENTWICKLUNG3_SORCERER_H

#include "npc.h"

class Sorcerer : public NPC{
protected:
    int magicPower;

public:
    //Konstruktor
    Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower)
        : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower){
        std::cout << "Zauberer " << this->getName() << ", " << this->getHealth() << " Lebenspunkte, "
                  << this->getGold() << " Gold, " << this->getArmor() << " Armor, "
                  << this->getMagicResistance() << " Magic Resistance, " << this->magicPower
                  << " Magic Power wurde erstellt." << std::endl;
    }

    //Destruktor
    virtual ~Sorcerer(){}

    virtual void attack(Character &enemy) override;
};

std::ostream &operator<<(std::ostream& out, const Sorcerer &s);



#endif //INC_3_1_SPIELEENTWICKLUNG3_SORCERER_H
