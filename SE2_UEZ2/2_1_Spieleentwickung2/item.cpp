#include <iostream>
#include "item.h"

void Item::initItem(const std::string& name, int gold) {
    this->name = name;
    this->value = gold;
    this->isValid = true;
}

void Item::initItem(void) {
    this->isValid = false;
}
