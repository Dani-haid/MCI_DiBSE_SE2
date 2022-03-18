#ifndef INC_3_1_SPIELEENTWICKLUNG3_ITEM_H
#define INC_3_1_SPIELEENTWICKLUNG3_ITEM_H

#include <string>

class Item {
private:
    std::string name;
    int value;
    bool isValid;

public:
    //Default Konstruktor
    Item():name(""), value(0), isValid(false){}
    //Konstruktor
    Item(std::string, int, bool): name(name), value(value), isValid(isValid){}

    //void initItem(const std::string& name, int gold);
    //void initItem(void);

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
