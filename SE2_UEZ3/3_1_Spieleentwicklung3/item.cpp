#include "item.h"

void Item::initItem(const std::string& name, int gold) {
    this->name = name;
    this->value = gold;
    this->isValid = true;
}

void Item::initItem(void) {
    this->isValid = false;
}

//Getter:
std::string Item::getName() const {
    return name;
}
int Item::getValue() const {
    return value;
}
bool Item::isIsValid() const{
    return isValid;
}

//Setter:
void Item::setName(std::string name) {
    this->name = name;
}
void Item::setValue(int value) {
    this->value = value;
}
void Item::setIsValid(bool isValid) {
    this->isValid = isValid;
}
