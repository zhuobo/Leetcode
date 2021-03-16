#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int left = 0, count = 0, res = 0;
        int len = nums.size();
        unordered_map<int, int> num_count;
        for ( int right = 0; right < len; ++right ) {
            if ( num_count[nums[right]] == 0 ) {
                ++count;
            }
            ++num_count[nums[right]];

            while ( count > k ) {
                --num_count[nums[left]];
                if ( num_count[nums[left]] == 0 ) {
                    --count;
                }
                ++left;
            }
            res += right - left;
        }
        return res;
    }
};
