#ifndef BOX_ID_H_
#define BOX_ID_H_

#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

class BoxId {
   public:
    std::string const id;
    std::unordered_set<int> occurances;

    BoxId() = default;
    BoxId(std::string i) : id{i}, occurances{} {
        std::multiset<char> char_occurances{};
        char_occurances.insert(id.cbegin(), id.cend());
        std::unordered_set<char> char_occurences_keys{id.cbegin(), id.cend()};

        for (auto const& occ : char_occurences_keys) {
            int count = char_occurances.count(occ);
            if (count > 1) {
                this->occurances.insert(count);
            }
        }
    };
    BoxId(BoxId const& box_id) = default;
    BoxId(BoxId&& box_id) = default;
    ~BoxId() = default;
};

std::ostream& operator<<(std::ostream& o, BoxId const& box);

#endif
