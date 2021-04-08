// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.08
// Filename:        436.cc
// Descripton:       

#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;
using std::sort;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<int> res(len, -1);
        map<vector<int>, int> interval_index;
        for ( int i = 0; i < len; ++i ) {
            interval_index[intervals[i]] = i;
        }
        vector<vector<int>> temp_intervals(intervals.begin(), intervals.end());
        std::sort(temp_intervals.begin(), temp_intervals.end());
        for ( int i = 0; i < len; ++i ) {
            int second = intervals[i][1];
            // 找到第一个大于second的区间
            int left = 0;
            int right = len - 1;
            while ( left < right ) {
                int mid = left + (right - left) / 2;
                if ( temp_intervals[mid][0] >= second ) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res[i] = temp_intervals[left][0] >= second ? interval_index[temp_intervals[left]] : -1;
        }
        return res;
    }
};
