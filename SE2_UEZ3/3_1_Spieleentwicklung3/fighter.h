#ifndef INC_3_1_SPIELEENTWICKLUNG3_FIGHTER_H
#define INC_3_1_SPIELEENTWICKLUNG3_FIGHTER_H

#include "npc.h"

class Fighter: public NPC{
protected:
    int strength;

public:
    //Konstruktor
    Fighter(const std::string& name, int health, int gold, int armor, int magicResistance, int strength)
        : NPC(name, health, gold, armor, magicResistance), strength(strength){
        std::cout << *this << ", " << this->getHealth() << " Lebenspunkte, "
                  << this->getGold() << " Gold, " << this->getArmor() << " Armor, "
                  << this->getMagicResistance() << " Magic Resistance, " << this->strength <<
                  " Strength wurde erstellt." << std::endl;
    }

    //Destruktor
    virtual ~Fighter(){}

    //friend Operatorenüberladung
    friend std::ostream &operator<<(std::ostream &out, const Fighter &f);

    virtual void attack(Character &enemy) override;

    //Getter:
    int getStrength() const;
    void setStrength(int strength);
};

std::ostream &operator<<(std::ostream& out, const Fighter &f);


#endif //INC_3_1_SPIELEENTWICKLUNG3_FIGHTER_H
