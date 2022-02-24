//
// Created by Daniela Haid on 21.02.22.
//

#ifndef CL_1_1_SPIELEENTWICKUNG_1_CHARACTER_H
#define CL_1_1_SPIELEENTWICKUNG_1_CHARACTER_H


#include <string>
#include "item.h"

//Forward declaration --> nochmal im Detail anschauen
struct Hero_t;

struct Character_t {
    std::string name;
    int health = 0;
    int gold = 0;
    Item_t inventory[10];
};

void initCharacter(Character_t* character, char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);


#endif //CL_1_1_SPIELEENTWICKUNG_1_CHARACTER_H
