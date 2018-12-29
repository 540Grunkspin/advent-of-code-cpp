#include "claim.hpp"
#include <regex>

static const std::regex claim_matcher{"#(\\d+)\\s+@\\s+(\\d+),(\\d+):\\s+(\\d+)x(\\d+)"};

std::ostream& operator<<(std::ostream& out, Claim const& claim) {
    return out << "#" << claim.id << " @ "
               << claim.point.x << "," << claim.point.y
               << ": " << claim.dimen.width << "x" << claim.dimen.height;
}

Claim const Claim::from_string(std::string const& input) {
    std::smatch matches;
    std::regex_match(input, matches, claim_matcher);

    int id = std::stoi(matches[1].str());

    int x = std::stoi(matches[2].str());
    int y = std::stoi(matches[3].str());

    Point point{x, y};

    int width = std::stoi(matches[4].str());
    int height = std::stoi(matches[5].str());

    Dimension dimen{width, height};

    return Claim{id, point, dimen};
}