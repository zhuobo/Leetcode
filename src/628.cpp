#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3, min1, min2;
        max1 = max1 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for ( int num : nums ) {
            if ( num < min1 ) {
                min2 = min1;
                min1 = num;
            } else if ( num < min2 ) {
                min2 = num;
            }

            if ( num > max1 ) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if ( num > max2 ) {
                max3 = max2;
                max2 = num;
            } else if ( num > max3 ) {
                max3 = num;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1, 2, 3, 4 };
    cout << s.maximumProduct(nums) << endl;
}
