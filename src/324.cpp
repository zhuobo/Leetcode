#include <vector>
#include <queue>
#include <algorithm>
using std::sort;
using std::vector;
using std::priority_queue;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int left = (len & 1) == 1 ? len / 2 : len / 2 - 1;
        int right = len - 1;
        int mid = left;
        int i = 0;
        while ( left >= 0 || right > mid ) {
            if ( left >= 0 ) nums[i++] = temp[left--];
            if ( right > mid ) nums[i++] = temp[right--];
        }
    }
};
