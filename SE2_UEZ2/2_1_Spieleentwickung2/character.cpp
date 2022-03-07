#include <iostream>
#include "character.h"
#include "hero.h"

void Character::initCharacter(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < 10; ++i) {
        this->inventory[i].initItem();
    }
}

//hier Referenz oder Pointer verwenden??
void Character::attack(Hero &hero) {
    //Gegner greift Heldin an und reduziert health random zwischen 5-15
    int damage = 5 + std::rand() % 11;
    int lifes = hero.getHealth();
    hero.setHealth(lifes - damage);
    std::cout<< this->name << " trifft " << hero.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
}

int Character::addInventarItem(const Item &item) {
    for (int i = 0; i < 10; ++i) {
        if(!this->inventory[i].isIsValid()){
            //wenn Platz auf false, also leer, dann füge Item hinzu
            this->inventory[i] = item;
            return i; //index im inventory zurückgeben
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

Item *Character::removeInventarItem(int slot) {
    if(this->inventory[slot].isIsValid()){ //wenn Eingabeslot gültig, dann isValid auf false setzen
        this->inventory[slot].setIsValid(false);
        return &this->inventory[slot]; //nochmal erklären lassen
    };
    return nullptr;
}

//Getter:
std::string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getGold() {
    return gold;
}

Item *Character::getInventory(int index) {
    if(this->inventory[index].isIsValid()){
        return &inventory[index]; //korrekt?
    };
    return nullptr; //check
}

//Setter:
void Character::setHealth(int health) {
    this->health = health;
}

void Character::setGold(int gold) {
    this->gold = gold;
}
