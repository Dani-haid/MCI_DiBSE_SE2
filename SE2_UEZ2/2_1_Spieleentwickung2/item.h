#ifndef INC_2_1_SPIELEENTWICKUNG2_ITEM_H
#define INC_2_1_SPIELEENTWICKUNG2_ITEM_H

#include <string>
#include <iostream>


class Item {

private:
    std::string name;
    int value;
    bool isValid;

public:
    //für was std::string& verwenden??
    void initItem(std::string name, int gold){
        this->name = name;
        this->value = gold;
        isValid = true; //hier auch this-> notwendig?
        std::cout << this->name << " " << this->value << " " << this->isValid << std::endl;
    };

    void initItem(void){
        isValid = false;
    };
};


#endif //INC_2_1_SPIELEENTWICKUNG2_ITEM_H
