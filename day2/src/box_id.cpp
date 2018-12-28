#include "box_id.h"
#include <iostream>

std::ostream& operator<<(std::ostream& o, BoxId const& box) {
    return o << "ID: " << box.id;
}

std::unordered_set<int> const& BoxId::getOccurances() const {
    return this->occurances;
}

char const& BoxId::operator[](std::size_t const index) const {
    return this->id[index];
}

std::size_t const BoxId::size() const {
    return this->id.size();
}

BoxIdDiff const BoxIdDiff::from_box_ids(BoxId const& b1, BoxId const& b2) {
    std::string kept = "";
    int diff_count = 0;
    for (std::size_t i = 0; i < b1.size() && i < b2.size(); i++) {
        if (b1[i] == b2[i]) {
            kept += b1[i];
        } else {
            diff_count += 1;
        }
    }

    return BoxIdDiff(kept, diff_count);
}

std::ostream& operator<<(std::ostream& o, BoxIdDiff const& diff) {
    return o << "Kept of id :" << diff.kept_chars;
}