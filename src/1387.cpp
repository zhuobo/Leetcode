#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class step {
public:
    bool operator()(int x, int y) {
        return (steps(x) < steps(y)) || (steps(x) == steps(y) && x < y);
    }
    int steps(int x) {
        int count = 0;
        while ( x != 1 ) {
            if ( x % 2 == 1 ) {
                x = 3 * x + 1;
            } else {
                x /= 2;
            }
            ++count;
        }
        return count;
    }

};

class Solution {
private:
public:
    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for ( int i = lo; i <= hi; ++i ) {
            nums.push_back(i);
        }
        sort(nums.begin(), nums.end(), step());
            return nums[k - 1];
    }
};
