#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using std::stack;
using std::vector;
using std::min;
using std::max;
using std::cout;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int res = 0;
        stack<int> stk;
        for ( int i = 0; i < len; ++i ) {
            while ( !stk.empty() && height[i] > height[stk.top()] ) {
                int curr_index = stk.top();
                stk.pop();
                if ( !stk.empty() ) {
                    int prev_index = stk.top();
                    res += (min(height[i], height[prev_index]) - height[curr_index]) * (i - prev_index - 1);
                }
            }
            stk.push(i);
        }
        return res;
    }
};


class Solution2 {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if ( len == 0 ) {
            return 0;
        }
        vector<int> left_max(len, 0);
        vector<int> right_max(len, 0);
        left_max[0] = height[0];
        right_max[len - 1] = height[len -1];
        for ( int i = 1; i < len; ++i ) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        for ( int i = len - 2; i >= 0; --i ) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        int res = 0;
        for ( int i = 0; i < len; ++i ) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};               

int main() {
    Solution2 s;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << s.trap(height);    
    return 0;
}
