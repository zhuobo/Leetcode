// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       判断一个数组中是否出现过132模式，132模式指的是：对于索引
// i < j < k, nums[i] < nums[k] < nums[j]

// solution: 遍历所有可能的nums[j], 左边维护一个最小值表示nums[i], nums[j]右边
// 是否出现了大于nums[i]并且小于nums[j]的数字

#ifndef SRC_456_H
#define SRC_456_H
#include <vector>
#include <set>
#include <algorithm>

using std::multiset;
using std::vector;
using std::min;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if ( len < 3 ) {
            return false;
        }
        int min_num = nums[0];
        multiset<int> right(nums.begin() + 2, nums.end());
        for ( int j = 1; j < len - 1; ++j ) {
            if ( nums[j] > min_num ) {
                // 找右边是否有大于min_num的数
                auto numk = right.upper_bound(min_num);
                if ( numk != right.end() && *numk < nums[j] ) {
                    return true;
                }
            }
            min_num = min(min_num, nums[j]);
            right.erase(right.find(nums[j + 1]));
        }
        return false;
    }
};

#endif 
