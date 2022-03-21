#include "item.h"

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
