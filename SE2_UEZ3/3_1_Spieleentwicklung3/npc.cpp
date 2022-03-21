#include "npc.h"
std::ostream &operator<<(std::ostream& out, const NPC &n){
    out << n.getName();
    return out;
};