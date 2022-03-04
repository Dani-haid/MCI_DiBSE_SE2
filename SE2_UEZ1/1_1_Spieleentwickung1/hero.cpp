#include "hero.h"
#include "character.h"
#include <cstdlib>
#include <iostream>

void initHero(Hero_t* hero, char* name, int health, int gold){
    hero->name = name;
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i < 10; ++i) {
        initItem(&hero->inventory[i]);
    }

    for (int i = 0; i < 2; ++i) {
        initItem(&hero->equipment[i]);
    }
};

void attack(Hero_t* hero, Character_t* enemy){
    //Heldin greift Gegener an und reduziert health random zwischen 15-25
    int damage = 15 + std::rand() % 11;
    enemy->health -= damage;
    std::cout<<hero->name << " trifft " << enemy->name << " für " << damage << " Lebenspunkte!" << std::endl;
};

void sellItem(Hero_t* hero, int index){
    if(index >= 0 && index < 10){
        if(hero->inventory[index].isValid){
            hero->gold += hero->inventory[index].value;
            hero->inventory[index].isValid = false;
            std::cout<<"Gegenstand " << hero->inventory[index].name << " wurde verkauft. " << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
        }
    }
};

bool fight(Hero_t* hero, Character_t* enemy){
    while(hero->health > 0 && enemy->health > 0){
            attack(hero, enemy);//Heldin greift Gegner an
            if(enemy->health > 0){
                attack(enemy, hero); //Gegner greift Heldin an
            }
    }
    return hero->health > 0;
};
