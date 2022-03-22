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
            std::cout<<"Gegenstand " << this->inventory[index] << "wurde verkauft. "
                     << *this << " besitzt nun " << this->gold << " Gold." << std::endl;
        }
    }
}

void Hero::attack(Character &enemy){
    //Die Heldin richtet einen Schaden gemäß folgender Formel an: damage = rand(15, 25) - Armor.
    int damage = (15 + std::rand() % 11) - enemy.getArmor();

    if(damage > 0){
        enemy.setHealth(enemy.getHealth() - damage);
        std::cout<< *this << " trifft " << enemy << " für " << damage << " Lebenspunkte!" << std::endl;
    }
    else{
        std::cout << "Angriff von " << *this << " war wirkungslos, Armor von "<< enemy << " zu hoch." << std::endl;
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
        std::cout<<enemy << " fiel in Ohnmacht! "<< *this <<
                 " hat noch "<< this->getHealth() << " Lebenspunkte uebrig!" <<std::endl;
        Item loot = this->retriveRandomLoot(enemy);
        if(loot.isIsValid()){
            if(this->addInventarItem(loot) < 0){
                std::cout<<"Kein Platz mehr vorhanden! Inventar von " << *this <<" ist voll."<<std::endl;
            };
        }
    }
    return this->health > 0;
}

//Getter:
Item* Hero::getEquipment(int index){
    if(index >= 0 && index < HERO_EQUIPMENT_SIZE){
        return &this->equipment[index];
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& out, const Hero& h) {
    out << "Held " << h.getName();
    return out;
}
