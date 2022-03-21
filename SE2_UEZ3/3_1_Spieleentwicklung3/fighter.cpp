#include "fighter.h"

void Fighter::attack(Character &enemy){
    //Der Kämpfer richtet einen Schaden gemäß folgender Formel an: damage = rand(5, 10) + Strength - Armor.
    int damage = (5 + std::rand() % 6) + this->strength - enemy.getArmor();
    enemy.setHealth(enemy.getHealth() - damage);
    std::cout<< this->name << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
}
