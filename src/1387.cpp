#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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


// Solution 2 using memo to reduce the calc
class Solution2 {
public:
    int calc_steps(std::unordered_map<int, int>& steps, int x) {
        if ( steps.find(x) != steps.end() ) {
            return steps[x];
        }
        if ( x == 1 ) {
            return steps[x] = 0;
        }
        if ( (x & 1) == 1 ) {
                return steps[x] = calc_steps(steps, 3 * x + 1) + 1;
        } else {
            return steps[x] = calc_steps(steps, x / 2) + 1;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        unordered_map<int, int> steps;
        for ( int i = lo; i <= hi; ++i ) {
            nums.push_back(i);
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if ( calc_steps(steps, a) != calc_steps(steps, b)  ) {
                return calc_steps(steps, a) < calc_steps(steps, b);
            } else {
                return a < b;
            }
        });
        return nums[k - 1];
    }
};
