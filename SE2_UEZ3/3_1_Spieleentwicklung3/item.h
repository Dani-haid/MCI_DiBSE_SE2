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
    Item():value(0), isValid(false){}

    //Konstruktor
    Item(const std::string& name, int value)
        : name(name), value(value), isValid(true){}

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

std::ostream &operator<<(std::ostream& out, const Item &i);


#endif //INC_3_1_SPIELEENTWICKLUNG3_ITEM_H
