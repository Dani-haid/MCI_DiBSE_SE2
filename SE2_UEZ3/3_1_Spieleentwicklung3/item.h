#ifndef INC_3_1_SPIELEENTWICKLUNG3_ITEM_H
#define INC_3_1_SPIELEENTWICKLUNG3_ITEM_H

#include <string>
#include <iostream>

class Item {
private:
    std::string name;
    int value;
    bool isValid;

public:
    //Default Konstruktor
    Item():name(""), value(0), isValid(false){
        //std::cout << "Default-Konstruktor Item.h aufgerufen" << std::endl;
    }
    //Konstruktor
    Item(const std::string& name, int value)
        : name(name), value(value), isValid(true){
        //std::cout << "Konstruktor Item.h aufgerufen" << std::endl;
    }

    //Destruktor
    ~Item(){};

    //Getter:
    const std::string& getName() const;
    int getValue() const;
    bool isIsValid() const;

    //Setter:
    void setName(const std:: string& name);
    void setValue(int value);
    void setIsValid(bool isValid);
};


#endif //INC_3_1_SPIELEENTWICKLUNG3_ITEM_H
