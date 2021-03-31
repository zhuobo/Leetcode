#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int>         path;
        backtrack(nums, res, path, 0);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int index) {
        res.emplace_back(path);
        for ( int i = index; i < nums.size(); ++i ) {
            if ( i > index && nums[i] == nums[i - 1] ) {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, res, path, i + 1);
            path.pop_back();
        }
    }
};
