#include <vector>
using std::vector;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if ( len <= 1 ) return true;
        int changed = false;
        for ( int i = 0; i < len - 1; ++i ) {
            if ( nums[i + 1] < nums[i] ) {
                if ( changed ) return false;
                if ( i == 0 ) {
                    nums[i] = nums[i + 1];
                } else{
                    if (nums[i + 1] < nums[i] ) {
                        if ( nums[i + 1] < nums[i - 1] ) {
                            nums[i + 1] = nums[i];
                        } else {
                            nums[i] = nums[i + 1];
                        }
                    }
                }
                changed = true;
            }
        }
        return true;
    }
};
