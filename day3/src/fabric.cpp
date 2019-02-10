#include "fabric.hpp"

#include <iostream>

void Fabric::add_claim(Claim const &claim) {
  auto point = claim.get_point();
  auto dimen = claim.get_dimension();
  bool double_claimed = false;
  for (int i = 0; i < dimen.height; i++) {
    for (int j = 0; j < dimen.width; j++) {
      int y = i + point.y;
      int x = j + point.x;
      int &square = this->squares[y][x];

      if (square == SquareType::unclaimed) {
        square = claim.get_id();
      } else {
        this->unique_claims.erase(square);
        double_claimed = true;

        square = SquareType::double_claimed;
      }
    }
  }
  if (!double_claimed) this->unique_claims.insert(claim.get_id());
}

int Fabric::colliding_claims_size() const {
  int counter = 0;
  for (auto &row : this->squares) {
    for (auto &square : row) {
      if (square == SquareType::double_claimed) {
        counter++;
      }
    }
  }

  return counter;
}