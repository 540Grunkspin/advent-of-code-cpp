#include "fabric.hpp"

#include <iostream>

void Fabric::add_claim(Claim const &claim) {
    auto point = claim.point;
    auto dimen = claim.dimen;
    for (int i = 0; i < dimen.height; i++) {
        for (int j = 0; j < dimen.width; j++) {
            int y = i + point.y;
            int x = j + point.x;
            int &square = this->squares[y][x];
            if (square == SquareType::unclaimed) {
                square = claim.id;
            } else {
                square = SquareType::double_claimed;
            }
        }
    }
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