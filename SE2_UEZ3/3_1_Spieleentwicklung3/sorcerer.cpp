#include "sorcerer.h"

void Sorcerer::attack(Character &enemy){
    //Der Zauberer richtet einen Schaden gemäß folgender Formel an:
    // damage = rand(5, 10) + MagicPower - MagicResistance.
    int damage = (5 + std::rand() % 6) + this->magicPower - enemy.getMagicResistance();
    if(damage > 0){
        enemy.setHealth(enemy.getHealth() - damage);
        std::cout<< *this << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    }
    else{
        std::cout << "Angriff von " << *this << " war wirkungslos, Magic Resistance von "<< enemy << " zu hoch." << std::endl;
    }
}

//Getter:
int Sorcerer::getMagicPower()const{
    return magicPower;
};
//Setter:
void Sorcerer::setMagicPower(int power){
    if(power >= 0){
        this->magicPower = power;
    }
};

std::ostream &operator<<(std::ostream& out, const Sorcerer &s){
    out << "Zauberer " <<s.getName();
    return out;
};
