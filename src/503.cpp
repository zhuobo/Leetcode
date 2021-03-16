#include <vector>
#include <stack>
#include <utility>

using std::vector;
using std::stack;
using std::pair;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> next_greater(len, -1);
        stack<pair<int, int>> stk; // num->index
        for ( int i = 0; i < len; ++i ) {
            while ( !stk.empty() && nums[i] > stk.top().first ) {
                int index = stk.top().second;
                stk.pop();
                next_greater[index] = nums[i];
            }
            stk.emplace(nums[i], i);
        }
        for ( int i = 0; i < len; ++i ) {
            while ( !stk.empty() && nums[i] > stk.top().first ) {
                int index = stk.top().second;
                stk.pop();
                next_greater[index] = nums[i];
            }
        }
        return next_greater;
    }
};


class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> stk;
        for ( int i = 0; i < len; ++i ) {
            while ( !stk.empty() && nums[stk.top()] < nums[i] ) {
                res[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for ( int i = 0; i < len; ++i ) {
            while ( !stk.empty() && nums[stk.top()] < nums[i] ) {
                res[stk.top()] = nums[i];
                stk.pop();
            }
        }
        return res;
    }
};


class Solution3 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> stk;
        for ( int i = 0; i < len * 2 - 1; ++i ) {
            while ( !stk.empty() && nums[stk.top()] < nums[i % len] ) {
                res[stk.top()] = nums[i % len];
                stk.pop();
            }
            stk.push(i % len);
        }
        return res;
    }
};
