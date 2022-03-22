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
        std::cout << *this << ", " << this->getHealth() << " Lebenspunkte, "
                  << this->getGold() << " Gold, " << this->getArmor() << " Armor, "
                  << this->getMagicResistance() << " Magic Resistance, " << this->magicPower
                  << " Magic Power wurde erstellt." << std::endl;
    }

    //Destruktor
    virtual ~Sorcerer(){}

    //friend Operatorenüberladung
    friend std::ostream &operator<<(std::ostream &out, const Sorcerer &s);

    virtual void attack(Character &enemy) override;

    //Getter:
    int getMagicPower()const;
    //Setter:
    void setMagicPower(int power);
};

std::ostream &operator<<(std::ostream& out, const Sorcerer &s);



#endif //INC_3_1_SPIELEENTWICKLUNG3_SORCERER_H
