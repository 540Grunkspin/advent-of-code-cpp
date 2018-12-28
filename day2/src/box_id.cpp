#include "box_id.h"
#include <iostream>

std::ostream& operator<<(std::ostream& o, BoxId const& box) {
    return o << "ID: " << box.id;
}

std::unordered_set<int> const& BoxId::getOccurances() const {
    return this->occurances;
}