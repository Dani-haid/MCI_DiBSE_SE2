#include "hero.h"

void Hero::initHero(const std::string& name, int health, int gold) {
    this->name = name;
    this->health = health;
    this->gold = gold;

    for (int i = 0; i < 10; ++i) {
        this->inventory[i].initItem();
        //Item inventory[i];
        //inventory[i].initItem();
    }

    for (int i = 0; i < 2; ++i) {
        this->equipment[i].initItem();
    }
}

/*void Hero::attack(Character &enemy) {
    //Heldin greift Gegener an und reduziert health random zwischen 15-25
    int damage = 15 + std::rand() % 11;
    enemy.reduceCharacterHealth(damage);
    std::cout<< name << " trifft " << enemy.get << " für " << damage << " Lebenspunkte!" << std::endl;
}*/
