#include "box_id.h"
#include <iostream>

std::ostream& operator<<(std::ostream& o, BoxId const& box) {
    return o << "ID: " << box.id;
}