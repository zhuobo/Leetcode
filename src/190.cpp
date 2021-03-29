// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.29
// Filename:        190.cpp
// Descripton:       

#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>

using std::string;
using std::bitset;
using std::reverse;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for ( int i = 0; i < 32; ++i ) {
            res += (n & 1) << (31 - i);
            n >>= 1;
        }
        return res;
    }

    uint32_t reverseBits2(uint32_t n) {
        bitset<32> num(n);
        string num_str = num.to_string();
        reverse(num_str.begin(), num_str.end());
        bitset<32> res(num_str);
        return static_cast<uint32_t>(res.to_ulong());
    }
};


int main() {
    Solution s;
    std::cout << s.reverseBits(10086) << std::endl;
    std::cout << s.reverseBits2(77882) << std::endl;
    return 0;
}

