#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
private:
    bool square(int num) {
        int sqrt_num = sqrt(num);
        return sqrt_num * sqrt_num == num;
    }

    void backtrack(vector<vector<int>>& permutation, vector<int>& path,
            vector<int>& nums, vector<bool>& visited, int depth) {
        if ( depth == nums.size() ) {
            permutation.emplace_back(path);
            return;
        }
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( !visited[i] ) {
                if ( i > 0 && nums[i] == nums[i - 1] && !visited[i - 1] ) {
                    continue;
                }
                // 保证生成排列都是正方形数组
                if ( path.size() > 0 && !square(path.back() + nums[i]) ) {
                    continue;
                }
                path.push_back(nums[i]);
                visited[i] = true;
                backtrack(permutation, path, nums, visited, depth + 1);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
  
public:
    int numSquarefulPerms(vector<int>& A) {
        int len = A.size();
        sort(A.begin(), A.end());
        vector<vector<int>> permutation;
        vector<int> path;
        vector<bool> visited(len, false);
        backtrack(permutation, path, A, visited, 0);
        return permutation.size();
    }
};
