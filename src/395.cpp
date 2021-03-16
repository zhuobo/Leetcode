#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::max;


class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size();
        vector<int> count(26, 0);
        for ( char c : s) {
            ++count[c - 'a'];
        }
        vector<int> cut_points;
        for ( int i = 0; i < len; ++i ) {
            if ( count[s[i] - 'a'] < k ) {
                cut_points.push_back(i);
            }
        }
        if ( cut_points.empty() ) {
            return len;
        }
        cut_points.push_back(s.size());
        int last_cut_point = 0, max_len = 0;
        for ( int cut_point : cut_points ) {
            int cur_len = cut_point - last_cut_point;
            if ( cur_len > max_len ) {
                max_len = max(max_len, longestSubstring(s.substr(last_cut_point, cur_len), k));
            }
            last_cut_point = cut_point + 1;
        }
        return max_len;
    }
};
