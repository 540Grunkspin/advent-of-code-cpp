#ifndef BOX_ID_H_
#define BOX_ID_H_

#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

class BoxId {
    friend std::ostream& operator<<(std::ostream& o, BoxId const& box);

   private:
    std::string const id;
    std::unordered_set<int> occurances;

   public:
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
    ~BoxId() = default;
    std::unordered_set<int> const& getOccurances() const;
    char const& operator[](std::size_t const index) const;
    std::size_t const size() const;
};

class BoxIdDiff {
    friend std::ostream& operator<<(std::ostream& o, BoxIdDiff const& diff);

   private:
    std::string const kept_chars;
    int const diff_count;
    BoxIdDiff(std::string const& kept, int const diff) : kept_chars{kept}, diff_count{diff} {};

   public:
    BoxIdDiff(BoxIdDiff const& other) = default;
    int get_diff_count() { return diff_count; }
    static BoxIdDiff const from_box_ids(BoxId const& b1, BoxId const& b2);
    ~BoxIdDiff() = default;
};

#endif
