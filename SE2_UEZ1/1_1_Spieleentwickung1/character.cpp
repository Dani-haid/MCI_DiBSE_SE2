//
// Created by Daniela Haid on 21.02.22.
//

#include <iostream>
#include "character.h"
#include "hero.h"
#include <ctime>
#include <cstdlib>

void initCharacter(Character_t *character, char *name, int health, int gold) {
    character->name = name;
    character->health = health;
    character->gold = gold;

    for (int i = 0; i < 10; ++i) {
        initItem(&character->inventory[i]);
    }

}

void attack(Character_t *character, Hero_t *hero) {
    //Gegner greift Heldin an und reduziert health random zwischen 5-15
    int randnumber = std::rand() % (15-5) + 5;
    hero->health -= randnumber;
    std::cout<<character->name << " trifft " << hero->name << " für " << randnumber << " Lebenspunkte!" << std::endl;
}
