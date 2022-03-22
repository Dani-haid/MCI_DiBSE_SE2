#include "fighter.h"

void Fighter::attack(Character &enemy){
    //Der Kämpfer richtet einen Schaden gemäß folgender Formel an: damage = rand(5, 10) + Strength - Armor.
    int damage = (5 + std::rand() % 6) + this->strength - enemy.getArmor();
    if(damage > 0){
        enemy.setHealth(enemy.getHealth() - damage);
        std::cout<< *this << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    }
    else{
        std::cout << "Angriff von " << *this << " war wirkungslos, Armor von "<< enemy << " zu hoch." << std::endl;
    }
}

//Getter:
int Fighter::getStrength() const{
    return strength;
};

void Fighter::setStrength(int strength){
    this->strength = strength;
};

std::ostream &operator<<(std::ostream& out, const Fighter &f){
    out << "Kämpfer " <<f.getName();
    return out;
};

