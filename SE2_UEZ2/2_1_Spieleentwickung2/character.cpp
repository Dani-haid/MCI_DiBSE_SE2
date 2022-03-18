#include <iostream>
#include "character.h"
#include "hero.h"

void Character::initCharacter(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i) {
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
    if(item.isIsValid()){
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i) {
            if(!inventory[i].isIsValid()){
                //wenn Platz auf false, also leer, dann füge Item hinzu
                this->inventory[i]=item;
                std::cout<<"Gegenstand " << this->inventory[i].getName() << " wurde an Stelle " << i << " zum Inventar von " << this->getName() << " hinzugefügt."<<std::endl;
                return i; //index im inventory zurückgeben
            }
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

Item Character::removeInventarItem(int slot) {
    if(slot >= 0 && slot < CHARACTER_INVENTORY_SIZE){
        Item temp = this->inventory[slot];
        this->inventory[slot].setIsValid(false); //wenn Eingabeslot gültig, dann isValid auf false setzen
        return temp;
    }
    Item temp;
    temp.initItem();
    return temp;
}

//Getter:
const std::string& Character::getName() const{
    return name;
}
int Character::getHealth() const{
    return health;
}
int Character::getGold() const{
    return gold;
}

Item *Character::getInventory(int index) {
    if(index >= 0 && index < CHARACTER_INVENTORY_SIZE){
        return &this->inventory[index];
    }
    return nullptr;
}

//Setter:
void Character::setName(const std::string& name){
    if(!name.empty()){
        this->name = name;
    }
};

void Character::setHealth(int health) {
    if(health < 0){
        this->health = 0;
    }
    this->health = health;
}

void Character::setGold(int gold) {
    if(gold >= 0){
        this->gold = gold;
    }
}
