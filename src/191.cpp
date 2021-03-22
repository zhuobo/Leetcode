// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.22
// Filename:        191.cpp
// Descripton:       

#include <inttypes.h>


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while ( n != 0 ) {
            ++count;
            n &= (n - 1);
        }
        return count;
    }
};



