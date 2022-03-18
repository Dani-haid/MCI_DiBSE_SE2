#include "item.h"

void Item::initItem(const std::string& name, int value) {
    this->name = name;
    this->value = value;
    this->isValid = true;
}

void Item::initItem(void) {
    this->isValid = false;
}

//Getter:
const std::string& Item::getName() const {
    return name;
}
int Item::getValue() const {
    return value;
}
bool Item::isIsValid() const{
    return isValid;
}

//Setter:
void Item::setName(const std:: string& name) {
    if(!name.empty()){
        this->name= name;
    }
}
void Item::setValue(int value) {
    if(value >= 0){
        this->value = value;
    }
}
void Item::setIsValid(bool isValid) {
    this->isValid = isValid;
}

