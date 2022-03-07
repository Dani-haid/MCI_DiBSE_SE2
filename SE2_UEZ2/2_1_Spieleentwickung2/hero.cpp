#include "hero.h"
#include "character.h"
#include <cstdlib>
#include <iostream>

void Hero::initHero(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < 10; ++i) {
        this->inventory[i].initItem();
    }

    for (int i = 0; i < 2; ++i) {
        this->equipment[i].initItem();
    }
}

void Hero::attack(Character &enemy){
    //Heldin greift Gegener an und reduziert health random zwischen 15-25
    int damage = 15 + std::rand() % 11;
    int lifes = enemy.getHealth();
    enemy.setHealth(lifes - damage);
    std::cout<< this->name << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
}

void Hero::sellItem(int index) {
    if(index >= 0 && index < 10){
        if(this->inventory[index].isIsValid()){
            this->gold += inventory[index].getValue();
            this->inventory[index].setIsValid(false);
            std::cout<<"Gegenstand " << this->inventory[index].getName() << " wurde verkauft. " << this->name << " besitzt nun " << this->gold << " Gold." << std::endl;
        }
    }
}

bool Hero::fight(Character &enemy) {
    while(this->health > 0 && enemy.getHealth() > 0){
        this->attack(enemy);//Heldin greift Gegner an
        if(enemy.getHealth() > 0){
            enemy.attack(*this); //Gegner greift Heldin an
        }
    }
    return this->health > 0;
}

int Hero::addInventarItem(const Item &item) {
    for (int i = 0; i < 10; ++i) {
        if(!this->inventory[i].isIsValid()){
            //wenn Platz auf false, also leer, dann füge Item hinzu
            this->inventory[i] = item;
            return i; //index im inventory zurückgeben
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

int Hero::addEquipmentItem(const Item &item) {
    for (int i = 0; i < 2; ++i) {
        if(!this->equipment[i].isIsValid()){
            //wenn Platz auf false, also leer, dann füge Item hinzu
            this->equipment[i] = item;
            return i; //index im inventory zurückgeben
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

Item *Hero::removeInventarItem(int slot) {
    if(this->inventory[slot].isIsValid()){ //wenn Eingabeslot gültig, dann isValid auf false setzen
        this->inventory[slot].setIsValid(false);
        return &this->inventory[slot];
    };
    return nullptr;
}

Item *Hero::removeEquipmentItem(int slot) {
    if(this->equipment[slot].isIsValid()){ //wenn Eingabeslot gültig, dann isValid auf false setzen
        this->equipment[slot].setIsValid(false);
        return &this->equipment[slot];
    };
    return nullptr;
}

//Getter:
std::string Hero::getName() {
    return name;
}

int Hero::getHealth() {
    return health;
}

int Hero::getGold() {
    return gold;
}

Item *Hero::getInventory(int index) {
    if(this->inventory[index].isIsValid()){
        return &inventory[index];
    };
    return nullptr; //check
}

Item *Hero::getEquipment(int index){
    if(this->equipment[index].isIsValid()){
        return &equipment[index];
    };
    return nullptr; //check
}

//Setter:
void Hero::setHealth(int health) {
    this->health -= health;
}

void Hero::setGold(int gold) {
    this->gold = gold;
}
