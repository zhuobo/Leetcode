#include <string>
#include <algorithm>
#include <unordered_set>

using std::string;
using std::unordered_set;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int                 max_len = 0;
        int                 len = s.size();
        int                 left = 0;
        int                 right = 0;
        while ( right < len ) {
            while ( window.find(s[right]) != window.end() ) {
                window.erase(s[left++]);
            }
            window.insert(s[right++]);
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
