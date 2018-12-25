#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "box_id.h"
#include "checksum.h"

std::vector<std::string> get_input_data(char const *const file_name);

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

    std::cout << checksum.calculate() << '\n';
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