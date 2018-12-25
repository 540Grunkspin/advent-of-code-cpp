#ifndef CHECK_SUM_H
#define CHECK_SUM_H

#include <set>
#include "box_id.h"

class CheckSum {
   private:
    std::multiset<int> occurance_count;

   public:
    CheckSum() = default;
    ~CheckSum() = default;
    void add_id(BoxId const& box_id);
    int calculate() const;
};

#endif