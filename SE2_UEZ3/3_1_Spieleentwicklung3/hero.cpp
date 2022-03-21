#include "hero.h"

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

Item Hero::removeEquipmentItem(int slot) {
    if(slot >= 0 && slot < HERO_EQUIPMENT_SIZE){
        Item temp = this->equipment[slot];
        this->equipment[slot].setIsValid(false);
        return temp;
    }
    Item temp;
    return temp;
}

void Hero::sellItem(int index) {
    if(index >= 0 && index < CHARACTER_INVENTORY_SIZE){
        if(this->inventory[index].isIsValid()){
            this->gold += inventory[index].getValue();
            this->inventory[index].setIsValid(false);
            std::cout<<"Gegenstand " << this->inventory[index].getName() << " wurde für "
                     << this->inventory[index].getValue() << " verkauft. "<< this->name
                     << " besitzt nun " << this->gold << " Gold." << std::endl;
        }
    }
}

void Hero::attack(Character &enemy){
    //Heldin greift Gegener an und reduziert health random zwischen 15-25
    int damage = 15 + std::rand() % 11;
    int lifes = enemy.getHealth();
    enemy.setHealth(lifes - damage);
    std::cout<< this->name << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
}

//Getter:
Item* Hero::getEquipment(int index){
    if(index >= 0 && index < HERO_EQUIPMENT_SIZE){
        return &this->equipment[index];
    }
    return nullptr;
}
