#ifndef INC_3_1_SPIELEENTWICKLUNG3_ITEM_H
#define INC_3_1_SPIELEENTWICKLUNG3_ITEM_H

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
    std::string getName() const;
    int getValue() const;
    bool isIsValid() const;

    //Setter:
    void setName(std:: string name);
    void setValue(int value);
    void setIsValid(bool isValid);
};


#endif //INC_3_1_SPIELEENTWICKLUNG3_ITEM_H
