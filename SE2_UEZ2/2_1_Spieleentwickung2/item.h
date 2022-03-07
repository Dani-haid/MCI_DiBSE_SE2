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

    //Getter für alle Eigenschaften:
    std::string getItemName() {
        return name;
    };
    int getItemValue() {
        return value;
    };
    bool getItemValidation() {
        return isValid;
    };

    //Hier ggf. noch Setter einfügen
    //********
};


#endif //INC_2_1_SPIELEENTWICKUNG2_ITEM_H
