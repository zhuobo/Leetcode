#include <vector>
#include <numeric>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& sum, vector<int>& path, int index) {
        sum.push_back(accumulate(path.begin(), path.end(), 0));
        if ( index == nums.size() ) return;
        for ( int i = index; i < nums.size(); ++i ) {
            path.push_back(nums[i]);
            backtrack(nums, sum, path, i + 1);
            path.pop_back();
        }
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int len = nums.size();
        vector<int> path;
        vector<int> left(nums.begin(), nums.begin() + len / 2);
        vector<int> right(nums.begin() + len / 2, nums.end());
        vector<int> sum_left, sum_right;
        backtrack(left, sum_left, path, 0);
        backtrack(right, sum_right, path, 0);
        sort(sum_left.begin(), sum_left.end());
        sort(sum_right.rbegin(), sum_right.rend());
        int i = 0, j = 0;
        int res = INT_MAX;
        while ( i < sum_left.size() && j < sum_right.size() ) {
            int cur_sum = sum_left[i] + sum_right[j];
            res = min(res, abs(cur_sum - goal));
            if ( cur_sum == goal ) {
                return 0;
            } else if ( cur_sum < goal ) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }
};
