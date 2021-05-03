// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if ( len == 1 ) {
            return nums[0];
        } else if ( len == 2 ) {
            return max(nums[0], nums[1]);
        }
        vector<int> get0(len, 0); // 第0户被偷获得的收益
        vector<int> pas0(len, 0); // 第0户不偷获得的收益
        get0[0] = nums[0];
        get0[1] = nums[0];
        pas0[0] = 0;
        pas0[1] = nums[1];
        for ( int i = 2; i < len - 1; ++i ) {
            get0[i] = max(get0[i - 1], get0[i - 2] + nums[i]);
            pas0[i] = max(pas0[i - 1], pas0[i - 2] + nums[i]);
        }
        get0[len - 1] = max(get0[len - 2], get0[len - 3]);
        pas0[len - 1] = max(pas0[len -2], pas0[len - 3] + nums[len - 1]);
        return max(get0[len - 1], pas0[len - 1]);
    }
};
