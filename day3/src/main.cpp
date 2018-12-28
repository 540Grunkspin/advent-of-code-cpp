#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "claim.hpp"

std::vector<std::string> get_input_data(char const *const file_name);

int main(int argc, char *argv[]) {
    auto input_strings = get_input_data(argv[1]);

    std::vector<Claim> claims;
    for (auto &input_string : input_strings) {
        claims.push_back(Claim::from_string(input_string));
    }

    std::cout << "All input parsed\n";
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