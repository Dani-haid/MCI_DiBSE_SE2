#ifndef INC_3_1_SPIELEENTWICKLUNG3_NPC_H
#define INC_3_1_SPIELEENTWICKLUNG3_NPC_H


#include "character.h"

class NPC : public Character{
public:
    //
    //Konstruktor
    NPC(const std::string& name, int health, int gold, int armor, int magicResistance)
            : Character(name, health, gold, armor, magicResistance){};
    //Destruktor
    ~NPC() {
        std::cout << "Gegner " << *this << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
    }
};

#endif //INC_3_1_SPIELEENTWICKLUNG3_NPC_H
