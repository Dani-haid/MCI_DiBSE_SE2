#ifndef CL_1_1_SPIELEENTWICKUNG_1_HERO_H
#define CL_1_1_SPIELEENTWICKUNG_1_HERO_H

#include <string>
#include "item.h"

//Forward declaration
struct Character_t;

struct Hero_t {
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
    Item_t equipment[2];
};


void initHero(Hero_t* hero, char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, Character_t* enemy);


#endif //CL_1_1_SPIELEENTWICKUNG_1_HERO_H
