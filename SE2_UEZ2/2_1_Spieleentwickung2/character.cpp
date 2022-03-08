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

void Character::attack(Hero &hero) {
    //Gegner greift Heldin an und reduziert health random zwischen 5-15
    int damage = 5 + std::rand() % 11;
    int lifes = hero.getHealth();
    hero.setHealth(lifes - damage);
    std::cout<< this->name << " trifft " << hero.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
}

int Character::addInventarItem(const Item& item) {
    for (int i = 0; i < 10; ++i) {
        if(!inventory[i].isIsValid()){
            //wenn Platz auf false, also leer, dann füge Item hinzu
            inventory[i] = item;
            this->inventory[i].setIsValid(true);
            std::cout<<"Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar von " << this->getName() << " hinzugefügt."<<std::endl;
            return i; //index im inventory zurückgeben
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

Item* Character::removeInventarItem(int slot) {
    if(this->inventory[slot].isIsValid()){ //wenn Eingabeslot gültig, dann isValid auf false setzen
        this->inventory[slot].setIsValid(false);
        //std::cout << inventory[slot].getName() << " an Stelle " << slot << " wurde bei " << this->getName() << " auf false gesetzt" << std::endl;
        Item& item = this->inventory[slot];
        return &item;
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
        Item& item = this->inventory[index];
        return &item;
    };
    return 0;//return false
}

//Setter:
void Character::setHealth(int health) {
    this->health = health;
}
void Character::setGold(int gold) {
    this->gold = gold;
}
