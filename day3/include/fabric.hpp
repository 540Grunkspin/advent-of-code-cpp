#ifndef FABRIC_H_
#define FABRIC_H_

#include <iterator>
#include <unordered_set>
#include <vector>
#include "claim.hpp"

enum SquareType {
  double_claimed = -1,
  unclaimed = 0,
};

class Fabric {
 private:
  std::vector<std::vector<int>> squares = std::vector<std::vector<int>>(
      1000, std::vector<int>(1000, SquareType::unclaimed));

  std::unordered_set<int> unique_claims;

 public:
  Fabric() = default;
  void add_claim(Claim const& claim);
  int colliding_claims_size() const;
  std::unordered_set<int>::const_iterator get_unique_claims() const { return this->unique_claims.begin(); };
};

#endif