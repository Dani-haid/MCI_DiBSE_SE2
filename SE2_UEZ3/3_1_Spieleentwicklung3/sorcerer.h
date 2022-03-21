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
        std::cout << "Calling Sorcerer::Constructor" << std::endl;
        std::cout << this->name << " " << this->magicPower << std::endl;
    }

    //Destruktor
    ~Sorcerer(){
        std::cout << "Calling Sorcerer::Destructor" << std::endl;
    }

    //virtual void attack(Character &enemy) override;

};


#endif //INC_3_1_SPIELEENTWICKLUNG3_SORCERER_H
