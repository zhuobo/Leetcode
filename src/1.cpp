#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int                     len = nums.size();
        vector<int>             res(2, -1);
        for ( int i = 0; i < len; ++i ) {
            if ( m.find(target - nums[i]) != m.end() ) {
                res[0] = m[target - nums[i]];
                res[1] = i;
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
