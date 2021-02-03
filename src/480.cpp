#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

// Solution1: sort every window
class Solution {
public:
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
        int len = nums.size();
        std::vector<double> res;
        if ( len < k ) {
            return res;
        }
        int left = 0;
        for ( int right = k; right <= len; ++right ) {
            std::vector<double> window(nums.begin() + left, nums.begin() + right);
            std::sort(window.begin(), window.end());
            if ( k % 2 == 1 ) {
                res.push_back(window[k / 2]);
            } else {
                res.push_back((double(window[k / 2]) + double(window[k / 2 + 1])) / 2);
            }
            ++left;
        }
        return res;
    }
};

class Median {
private:
    multiset<int> data;
    multiset<int>::iterator mid;
public:
    Median() : mid(data.end()) {}

    void addNum(int num) {
        const int len = data.size();
        data.insert(num);
        if ( len == 0 ) {
            mid = data.begin();
        } else if ( num < *mid ) {
            mid = (len & 1) == 0 ? prev(mid) : mid;
        } else {
            mid = (len & 1) == 0 ? mid : next(mid);
        }
    }

    double findMedian() {
        const int len = data.size();
        return ((double)*mid + *next(mid, len % 2 - 1)) * 0.5;
    }

    multiset<int>::iterator findNum(int num) {
        return data.find(num);
    }

    void removeNum(multiset<int>::iterator iter) {
        const int len = data.size();
        int num = *iter;
        if ( len == 0 ) {
            return;
        } else if ( len == 1 ) {
            mid = data.end();
        } else if ( num < *mid ) {
            mid = (len & 1) == 0 ? mid : next(mid);
        } else if ( num > *mid ) {
            mid = (len & 1) == 0 ? prev(mid) : mid;
        } else {
            if ( mid == iter ) {
                mid = (len & 1) == 0 ? prev(mid) : next(mid);
            } else {
                mid = (len & 1) == 0 ? mid : next(mid);
            }
        }
        data.erase(iter);
    }
};

// Solution2: 
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        Median median;
        vector<double> res;
        for ( int i = 0; i < len; ++i ) {
            median.addNum(nums[i]);
            if ( i >= k ) {
                auto iter = median.findNum(nums[i - k]);
                median.removeNum(iter);
            }
            if ( i >= k - 1 ) res.push_back(median.findMedian());
        }
        return res;
    }
};
