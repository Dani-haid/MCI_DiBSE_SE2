#include "item.h"

void initItem(Item_t *ITEM, char *name, int gold) {
    ITEM->name = name;
    ITEM->value = gold;
    ITEM->isValid = true;
}

//basic Initalisierung wenn sonst nichts vorhanden ist
void initItem(Item_t *gegenstand) {
    gegenstand->isValid = false;
}
