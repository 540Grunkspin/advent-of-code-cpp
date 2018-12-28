#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "box_id.h"
#include "checksum.h"

std::vector<std::string> get_input_data(char const *const file_name);
BoxIdDiff find_correct_diff(std::vector<BoxId> const &box_ids);

struct BoxDiffNotFountException : public std::exception {
    char const *what() const throw() {
        return "Box ids with 1 character diff could not be found";
    }
};

int main(int argc, char *argv[]) {
    auto input_data = get_input_data(argv[1]);
    std::vector<BoxId> box_ids;
    CheckSum checksum{};

    for (auto &str : input_data) {
        box_ids.push_back(BoxId{str});
    }

    for (auto const &box_id : box_ids) {
        checksum.add_id(box_id);
    }

    std::cout << "Checksum is: " << checksum.calculate() << '\n';
    std::cout << "Diffed leftover is: " << find_correct_diff(box_ids) << '\n';
}

BoxIdDiff find_correct_diff(std::vector<BoxId> const &box_ids) {
    for (std::size_t i = 0; i < box_ids.size(); i++) {
        for (std::size_t j = i + 1; j < box_ids.size(); j++) {
            BoxIdDiff diff = BoxIdDiff::from_box_ids(box_ids[i], box_ids[j]);
            if (diff.get_diff_count() < 2) {
                return diff;
            }
        }
    }

    throw BoxDiffNotFountException();
}

std::vector<std::string> get_input_data(char const *const file_name) {
    std::ifstream ifs{file_name};
    std::string tmp_str;

    std::vector<std::string> result;

    while (std::getline(ifs, tmp_str, '\n')) {
        result.push_back(tmp_str);
    }

    return result;
}