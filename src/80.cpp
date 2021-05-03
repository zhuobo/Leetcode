#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if ( len <= 2 ) {
            return len;
        }
        int left = 1;
        int right = 2;
        while ( right < len ) {
            if ( nums[right] != nums[left - 1] ) {
                nums[++left] = nums[right];
            }
            ++right;
        }
        return left + 1;
    }
};
