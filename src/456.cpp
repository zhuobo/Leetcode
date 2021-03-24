// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.24
// Filename:        
// Descripton:       
#include <vector>
#include <stack>
#include <limits>

using std::vector;
using std::stack;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = std::numeric_limits<int>::min();
        int len = nums.size();
        stack<int> stk;
        for ( int i = len - 1; i >= 0; --i ) {
            if ( nums[i] < two ) {
                return true;
            } else {
                while ( !stk.empty() && nums[i] > nums[stk.top()] ) {
                    two = nums[stk.top()];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return false;
    }
};
