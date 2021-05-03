#include <vector>

using std::vector;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while ( left <= right ) {
            int mid = left + (right - left) / 2;
            if ( nums[mid] == target ) {
                return true;
            }
            if ( nums[left] == nums[mid] ) {
                ++left;
            } else if ( nums[left] < nums[mid] ) {
                // 前半部分有序
                if ( target >= nums[left] && target < nums[mid] ) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // 后半部分有序
                if ( target > nums[mid] && target <= nums[right] ) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = { 2,5,6,0,0,1,2 };
    int target = 3;
    s.search(nums, target);
    target = 4;
    s.search(nums, target);
}
