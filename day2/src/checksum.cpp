#include "checksum.h"

#include <iostream>
#include <unordered_set>

void CheckSum::add_id(BoxId const& box_id) {
    this->occurance_count.insert(box_id.occurances.cbegin(), box_id.occurances.cend());
}

int CheckSum::calculate() const {
    int sum = 1;
    std::unordered_set<int> occurance_count_keys{this->occurance_count.cbegin(), this->occurance_count.cend()};
    for (auto& occurance_number : occurance_count_keys) {
        sum = sum * this->occurance_count.count(occurance_number);
    }

    return sum;
}