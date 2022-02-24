#ifndef CL_1_1_SPIELEENTWICKUNG_1_HERO_H
#define CL_1_1_SPIELEENTWICKUNG_1_HERO_H

//Forward declaration
struct Character_t;

#include <string>
#include "item.h"
#include "character.h"


struct Hero_t {
    std::string name;
    int health = 0;
    int gold = 0;
    Item_t inventory[10];
    Item_t equipment[2];
    //Item_t inventory[12]; //muss Inventar und Ausrüstung getrennt werden?
};


void initHero(Hero_t* hero, char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
bool fight(Hero_t* hero, Character_t* enemy);


#endif //CL_1_1_SPIELEENTWICKUNG_1_HERO_H
