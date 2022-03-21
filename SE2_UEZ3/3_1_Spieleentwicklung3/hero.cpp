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
    //Die Heldin richtet einen Schaden gemäß folgender Formel an: damage = rand(15, 25) - Armor.
    int rand = (15 + std::rand() % 11);
    int damage = rand - enemy.getArmor();
    //int damage = (15 + std::rand() % 11) - enemy.getArmor();
    enemy.setHealth(enemy.getHealth() - damage);
    std::cout<< this->name << " trifft " << enemy.getName() << " für " << damage << " Lebenspunkte!" << std::endl;
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
Item* Hero::getEquipment(int index){
    if(index >= 0 && index < HERO_EQUIPMENT_SIZE){
        return &this->equipment[index];
    }
    return nullptr;
}
