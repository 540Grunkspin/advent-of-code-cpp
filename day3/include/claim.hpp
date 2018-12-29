#ifndef CLAIM_H_
#define CLAIM_H_

#include <iostream>
#include <string>

struct Point {
    int const x;
    int const y;

    Point(int const x_pos, int const y_pos) : x{x_pos}, y{y_pos} {};
};

struct Dimension {
    int const width;
    int const height;

    Dimension(int const w, int const h) : width{w}, height{h} {};
};

class Claim {
   private:
    Claim(int const i, Point const p, Dimension const d) : id{i}, point{p}, dimen{d} {};

   public:
    int const id;
    Point const point;
    Dimension const dimen;
    static Claim const from_string(std::string const& input);
    friend std::ostream& operator<<(std::ostream& out, Claim const& claim);
};

#endif
