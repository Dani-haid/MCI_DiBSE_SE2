//
// Created by Daniela Haid on 21.02.22.
//

#ifndef CL_1_1_SPIELEENTWICKUNG_1_ITEM_H
#define CL_1_1_SPIELEENTWICKUNG_1_ITEM_H


#include <string>

struct Item_t {
    std::string name;
    int value = 0;
    bool isValid;
};

void initItem(Item_t* ITEM, char* name, int gold);
void initItem(Item_t* gegenstand);



#endif //CL_1_1_SPIELEENTWICKUNG_1_ITEM_H
