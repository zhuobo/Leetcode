// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:      最长递增子序列的长度以及真正的最长递增子序列

#include <algorithm>
#include <vector>

using std::vector;
using std::lower_bound;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if ( len <= 1 ) {
            return len;
        }
        vector<int> res; // 结果数组，不是最终的结果
        vector<int> max_len; // max_len[i]表示以nums[i]为结尾的最长递增子序列长度
        res.push_back(nums[0]);
        max_len.push_back(1);
        for ( int i = 1; i < len; ++i ) {
            if ( nums[i] > res.back() ) {
                res.push_back(nums[i]);
                max_len.push_back(res.size());
            } else {
                // 找到第一个大于等于nums[i]的数，然后替换
                int pos = std::lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[pos] = nums[i];
                max_len.push_back(pos + 1);
            }
        }
        // res.size() 就是结果，但res不是真正的结果
        int j = res.size();
        for ( int i = max_len.size() - 1; i >= 0; --i ) {
            if ( max_len[i] == j ) {
                res[--j] = nums[i];
            }
        }
        return res.size();
    }
};
