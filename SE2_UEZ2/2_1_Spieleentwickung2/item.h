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
    void initItem(const std::string& name, int gold);
    void initItem(void);

    //Getter:
    std::string getName();
    int getValue();
    bool isIsValid();

    //Setter:
    void setName(std:: string name);
    void setValue(int value);
    void setIsValid(bool isValid);
};


#endif //INC_2_1_SPIELEENTWICKUNG2_ITEM_H
