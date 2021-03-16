#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<pair<int, int>> que; // (index, val)
        int len = nums.size();
        for ( int i = 0; i < k; ++i ) {
            while ( !que.empty() && que.back().second < nums[i] ) {
                que.pop_back();
            } 
            que.emplace_back(i, nums[i]);
        }
        res.push_back(que.front().second);
        for ( int i = k; i < len; ++i ) {
            while ( !que.empty() && que.back().second <= nums[i] ) {
                que.pop_back();
            }
            while ( !que.empty() && i - k >= que.front().first ) {
                que.pop_front();
            }
            que.emplace_back(i, nums[i]);
            res.push_back(que.front().second);
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> que;
        int len = nums.size();
        for ( int i = 0; i < len; ++i ) {
            if ( i >= k && !que.empty() && nums[i - k] <= que.front() ) que.pop_front();
            while ( !que.empty() && que.back() < nums[i] ) {
                que.pop_back();
            }
            que.push_back(nums[i]);
            if ( i >= k - 1) res.push_back(que.front());
        }
        return res;
    }
};
