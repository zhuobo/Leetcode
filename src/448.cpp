#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for ( int i = 0; i < len; ++i ) {
            while ( nums[nums[i] - 1] != nums[i] ) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> not_occur;
        for ( int i = 0; i < len; ++i ) {
            if ( nums[i] != i + 1 ) {
                not_occur.push_back(i + 1);
            }
        }
        return not_occur;
    }   
};
