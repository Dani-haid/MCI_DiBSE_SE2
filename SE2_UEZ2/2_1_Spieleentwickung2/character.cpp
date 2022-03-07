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

//hier Referenz oder Pointer verwenden??
void Character::attack(Hero &hero) {
    //Gegner greift Heldin an und reduziert health random zwischen 5-15
    int damage = 5 + std::rand() % 11;
    hero.reduceHeroHealth(damage);
    std::cout<< this->name << " trifft " << hero.getHeroName() << " für " << damage << " Lebenspunkte!" << std::endl;
}
