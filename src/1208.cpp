#include <string>
using std::string;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int left = 0, right = 0;
        int cur_cost = 0, max_len = 0;
        while ( right < len ) {
            cur_cost += abs(s[right] - t[right]);
            // if is also works well
            while ( cur_cost > maxCost ) {
                cur_cost -= abs(s[left] - t[left]);
                ++left;
            }
            ++right;
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
