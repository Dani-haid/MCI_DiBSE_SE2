#ifndef INC_3_1_SPIELEENTWICKLUNG3_NPC_H
#define INC_3_1_SPIELEENTWICKLUNG3_NPC_H


#include "character.h"

class NPC : public Character{
public:
    //
    //Konstruktor
    NPC(const std::string& name, int health, int gold, int armor, int magicResistance)
            : Character(name, health, gold, armor, magicResistance){
        std::cout << "Calling NPC::Constructor" << std::endl;
    };
    //Destruktor
    virtual ~NPC() {
        std::cout << "Calling NPC::Destructor" << std::endl;
    }

    virtual void attack(Character &enemy) override;

    //wird hier eig. nicht gebraucht weil ja an sorcerer und fighter weitervererbt!
    /*virtual void attack()override {
        std::cout << "virtuelle attack funktion in npc.h" << std::endl;
    };*/

};


#endif //INC_3_1_SPIELEENTWICKLUNG3_NPC_H
