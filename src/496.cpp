#include <vector>
#include <stack>
#include <unordered_map>

using std::vector;
using std::stack;
using std::unordered_map;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        vector<int> res(len1, -1);
        stack<int> stk;
        unordered_map<int, int> m; // num->next_greater_num
        for ( int num : nums2 ) {
            while ( !stk.empty() && stk.top() < num ) {
                m[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        for ( int i = 0; i < len1; ++i ) {
            if ( m.find(nums1[i]) != m.end() ) {
                res[i] = m[nums1[i]];
            }
        }
        return res;
    }
};
