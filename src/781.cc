// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.08
// Filename:        781.cc
// Descripton:       

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int res = 0;
        for ( int answer : answers ) {
            ++count[answer];
        }
        for ( const auto& p : count ) {
            int groups = p.second / (p.first + 1);
            if ( p.second % (p.first + 1) != 0 ) {
                ++groups;
            }
            res += groups * (p.first + 1);
        }
        return res;
    }
};
