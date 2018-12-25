#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::string> get_input(char const *const file);

int main(int argc, char *argv[]) {
    auto const input = get_input(argv[1]);
    std::vector<int> numbers;
    numbers.resize(input.size());
    std::transform(input.cbegin(), input.cend(), numbers.begin(), [](auto s) { return atoi(s.c_str()); });

    std::unordered_set<int> frequencies;
    int current_freq = 0;

    bool did_insert;
    do {
        for (int &number : numbers) {
            current_freq += number;
            did_insert = frequencies.insert(current_freq).second;
            if (!did_insert) {
                break;
            }
        }
    } while (did_insert);

    std::cout << "Exercise 1: " << std::accumulate(numbers.cbegin(), numbers.cend(), 0) << '\n';
    std::cout << "Exercise 2: " << current_freq;

    return 0;
}

std::vector<std::string> get_input(char const *const file) {
    std::ifstream ifs{file};

    std::string tmp_in;
    std::vector<std::string> lines;
    while (std::getline(ifs, tmp_in, '\n')) {
        lines.push_back(tmp_in);
    }

    return lines;
}