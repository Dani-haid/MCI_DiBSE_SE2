#include "character.h"


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

int Character::getArmor() const {
    return armor;
}

int Character::getMagicResistance() const {
    return magicResistance;
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

void Character::setArmor(int armor) {
    this->armor = armor;
}

void Character::setMagicResistance(int magicResistance) {
    this->magicResistance = magicResistance;
}


