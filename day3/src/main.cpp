#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "claim.hpp"
#include "fabric.hpp"

std::vector<std::string> get_input_data(char const *const file_name);

int main(int argc, char *argv[]) {
  Fabric fabric{};
  auto input_strings = get_input_data(argv[1]);

  std::vector<Claim> claims;
  for (auto &input_string : input_strings) {
    claims.push_back(Claim::from_string(input_string));
  }

  for (auto &claim : claims) {
    fabric.add_claim(claim);
  }

  std::cout << "Colliding size is: " << fabric.colliding_claims_size() << '\n';
  std::cout << "Unique iterator: " << *fabric.get_unique_claims() << '\n';

  return 0;
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