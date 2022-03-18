#include "hero.h"
#include "character.h"
#include <cstdlib>
#include <iostream>

void Hero::initHero(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < HERO_INVENTORY_SIZE; ++i) {
        this->inventory[i].initItem();
    }

    for (int i = 0; i < HERO_EQUIPMENT_SIZE; ++i) {
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
    if(index >= 0 && index < HERO_INVENTORY_SIZE){
        if(this->inventory[index].isIsValid()){
            this->gold += inventory[index].getValue();
            this->inventory[index].setIsValid(false);
            std::cout<<"Gegenstand " << this->inventory[index].getName() << " wurde für "
            << this->inventory[index].getValue() << " verkauft. "<< this->name
            << " besitzt nun " << this->gold << " Gold." << std::endl;
        }
    }
}

bool Hero::fight(Character &enemy) {
    std::cout << "--------------------" << std::endl;
    std::cout << "Kampf " << this->getName() << " gegen " << enemy.getName() << " beginnt!" << std::endl;
    while(this->health > 0 && enemy.getHealth() > 0){
        this->attack(enemy);//Heldin greift Gegner an
        if(enemy.getHealth() > 0){
            enemy.attack(*this); //Gegner greift Heldin an
        }
    }

    if(this->health > 0){
        std::cout<<enemy.getName() << " fiel in Ohnmacht! "<< this->getName() <<
        " hat noch "<< this->getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        this->stealRandomItem(enemy);
    }

    //------tbd------//

    return this->health > 0;
}

int Hero::addInventarItem(const Item &item) {
    if(item.isIsValid()){
        for (int i = 0; i < HERO_INVENTORY_SIZE; ++i) {
            if(!this->inventory[i].isIsValid()){//wenn Platz auf false, also leer, dann füge Item hinzu
                this->inventory[i] = item;
                std::cout<<"Gegenstand " << this->inventory[i].getName() << " wurde an Stelle "
                << i << " zum Inventar von " << this->getName() << " hinzugefügt."<<std::endl;
                return i; //index im inventory zurückgeben
            }
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

int Hero::addEquipmentItem(const Item &item) {
    if(item.isIsValid()){
        for (int i = 0; i < HERO_EQUIPMENT_SIZE; ++i) {
            if(!this->equipment[i].isIsValid()){//wenn Platz auf false, also leer, dann füge Item hinzu
                this->equipment[i] = item;
                std::cout<<"Gegenstand " << this->equipment[i].getName() << " wurde an Stelle "
                << i << " zum Equipment der Heldin hinzugefügt."<<std::endl;
                return i; //index im inventory zurückgeben
            }
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
}

Item Hero::removeInventarItem(int slot) {
    if(slot >= 0 && slot < HERO_INVENTORY_SIZE){
        Item temp = this->inventory[slot];
        this->inventory[slot].setIsValid(false);
        return temp;
    }
    Item temp;
    temp.initItem();
    return temp;
}


Item Hero::removeEquipmentItem(int slot) {
    if(slot >= 0 && slot < HERO_EQUIPMENT_SIZE){
        Item temp = this->equipment[slot];
        this->equipment[slot].setIsValid(false);
        return temp;
    }
    Item temp;
    temp.initItem();
    return temp;
}

int Hero::stealRandomItem(Character &enemy){
    //ggf. etwas effizienter schreiben
    int randomNumbers [CHARACTER_INVENTORY_SIZE] = {-1};//Array für gültige Indexes des Inventories von Character
    int count = 0;
    for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i) {
        if(enemy.getInventory(i)->isIsValid()){
            randomNumbers[count] = i;
            count ++;
        }
    }
    if(randomNumbers[0] < 0){//Wenn Array an index 0 leer ist, hat der Gegner keine Items in seinem Inventar
        std::cout << "keine Items im Inventar von "<< enemy.getName() <<" gefunden." << std:: endl;
        return 0;
    }


    while(1){
        int random = randomNumbers[std::rand() % (count)]; //generiere Zufallszahl
        Item temp = enemy.removeInventarItem(random);
        if(temp.isIsValid()){
            if(this->addInventarItem(temp) < 0){
                std::cout<<"Kein Platz mehr vorhanden! Inventar von " << this->getName() <<" ist voll."<<std::endl;
            };
            break;
        }
    }
    return health > 0;
};

//Getter:
const std::string& Hero::getName() const{
    return name;
}

int Hero::getHealth() const{
    return health;
}

int Hero::getGold() const{
    return gold;
}

Item* Hero::getInventory(int index) {
    if(index >= 0 && index < HERO_INVENTORY_SIZE){
        return &this->inventory[index];
    }
    return nullptr;
}

Item* Hero::getEquipment(int index){
    if(index >= 0 && index < HERO_EQUIPMENT_SIZE){
        return &this->equipment[index];
    }
    return nullptr;
}

//Setter:
void Hero::setName(const std::string &name) {
    if (!name.empty()) {
        this->name = name;
    }
}

void Hero::setHealth(int health) {
    if(health < 0){
        this->health = 0;
    }
    this->health = health;
}

void Hero::setGold(int gold) {
    if(gold >= 0){
        this->gold = gold;
    }
}
