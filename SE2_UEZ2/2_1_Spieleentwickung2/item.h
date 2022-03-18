#ifndef INC_2_1_SPIELEENTWICKUNG2_ITEM_H
#define INC_2_1_SPIELEENTWICKUNG2_ITEM_H

#include <string>

class Item {
private:
    std::string name;
    int value;
    bool isValid;

public:
    void initItem(const std::string& name, int value);
    void initItem(void);

    //Getter:
    const std::string& getName() const;
    int getValue() const;
    bool isIsValid() const;

    //Setter:
    void setName(const std:: string& name);
    void setValue(int value);
    void setIsValid(bool isValid);
};


#endif //INC_2_1_SPIELEENTWICKUNG2_ITEM_H
