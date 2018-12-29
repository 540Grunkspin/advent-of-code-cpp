#ifndef FABRIC_H_
#define FABRIC_H_

#include <vector>
#include "claim.hpp"

enum SquareType {
    double_claimed = -1,
    unclaimed = 0,
};

class Fabric {
   private:
    std::vector<std::vector<int>> squares;

   public:
    Fabric() : squares{} {
        squares.resize(1000);
        for (int i = 0; i < 1000; i++) {
            squares[i].resize(1000);
            for (int& square : squares[i]) {
                square = SquareType::unclaimed;
            }
        }
    }
    void add_claim(Claim const& claim);
    int colliding_claims_size() const;
};

#endif