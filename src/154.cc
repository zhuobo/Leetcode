// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.08
// Filename:        154.cc
// Descripton:       

#include <vector>

using std::vector;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while ( left < right ) {
            int mid = left + (right - left) / 2;
            if ( nums[mid] == nums[right] ) {
                --right;
            } else if ( nums[mid] < nums[right] ) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
