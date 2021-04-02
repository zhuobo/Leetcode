#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if ( len <= 1 ) {
            return len;
        }
        int curr = 0;
        int next = 1;
        while ( next < len ) {
            if ( nums[next] != nums[curr] ) {
                nums[++curr] = nums[next];
            }
            ++next;
        }
        return curr + 1;
    }
};
