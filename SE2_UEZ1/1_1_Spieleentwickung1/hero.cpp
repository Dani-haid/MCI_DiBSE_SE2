//
// Created by Daniela Haid on 21.02.22.
//

#include "hero.h"
#include "character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void initHero(Hero_t* hero, char* name, int health, int gold){
    hero->name = name;
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i < 12; ++i) {
        initItem(&hero->inventory[i]);
    }
};

void attack(Hero_t* hero, Character_t* enemy){
    //Heldin greift Gegener an und reduziert health random zwischen 15-25
    int damage = std::rand() % (25-15) + 15;
    enemy->health -= damage;
    std::cout<<hero->name << " trifft " << enemy->name << " für " << damage << " Lebenspunkte!" << std::endl;
};

void sellItem(Hero_t* hero, int index){
            hero->gold += hero->inventory[index].value;
            hero->inventory[index].isValid = false;
            std::cout<<"Gegenstand " << hero->inventory[index].name << " wurde verkauft. " << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
};

bool fight(Hero_t* hero, Character_t* enemy){

    while(hero->health > 0 && enemy->health > 0){
            attack(hero, enemy);//Heldin greift Gegner an //wieso braucht man jetzt hier keinen & ?
            if (enemy->health <= 0){
                std::cout<<enemy->name << " fiel in Ohnmacht! "<< hero->name << " hat noch " << hero->health << " Lebenspunkte uebrig!" <<std::endl;
                return true; //Heldin gewinnt
            }
            attack(enemy, hero); //Gegner greift Heldin an
            if (hero->health <= 0){
                std::cout<<hero->name << " fiel in Ohnmacht! "<< enemy->name << " hat noch " << enemy->health << " Lebenspunkte uebrig!" <<std::endl;
                return false; //Gegner gewinnt
            }
    }
    return hero->health>0;
};
