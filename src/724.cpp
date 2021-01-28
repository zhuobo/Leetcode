#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int len = nums.size(), cur_sum = 0;
        for ( int i = 0; i < len; ++i ) {
            if ( cur_sum == sum - cur_sum - nums[i] ) {
                return i;
            }
            cur_sum += nums[i];
        }
        return -1;
    }
};
