#include "sorcerer.h"

void Sorcerer::attack(Character &enemy){
    //Der Zauberer richtet einen Schaden gemäß folgender Formel an:
    // damage = rand(5, 10) + MagicPower - MagicResistance.
    int damage = (5 + std::rand() % 6) +this->magicPower - enemy.getMagicResistance();
    enemy.setHealth(enemy.getHealth() - damage);
    std::cout<< this->name << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
}
