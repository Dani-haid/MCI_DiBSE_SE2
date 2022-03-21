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
        std::cout << "Calling Fighter::Constructor" << std::endl;
    }

    //Destruktor
    virtual ~Fighter(){}

    virtual void attack(Character &enemy) override;
};


#endif //INC_3_1_SPIELEENTWICKLUNG3_FIGHTER_H
