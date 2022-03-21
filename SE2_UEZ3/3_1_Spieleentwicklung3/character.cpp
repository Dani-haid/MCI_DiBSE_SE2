#include "character.h"

int Character::addInventarItem(const Item& item){
    if(item.isIsValid()){
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; ++i) {
            if(!this->inventory[i].isIsValid()){//wenn Platz auf false, also leer, dann füge Item hinzu
                this->inventory[i] = item;
                std::cout<<"Gegenstand " << this->inventory[i].getName() << " wurde an Stelle "
                         << i << " zum Inventar von " << this->getName() << " hinzugefügt."<<std::endl;
                return i; //index im inventory zurückgeben
            }
        }
    }
    return -1; //wenn alle Plätze belegt, return -1;
};

Item Character::removeInventarItem(int slot) {
    if(slot >= 0 && slot < CHARACTER_INVENTORY_SIZE){
        Item temp = this->inventory[slot];
        this->inventory[slot].setIsValid(false);
        return temp;
    }
    Item temp;
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

/*std::ostream &operator<<(std::ostream &out, const Character &c){
    out << c.getName() <<"Operatorenüberladung in Hero.h";
    return out;
}*/


