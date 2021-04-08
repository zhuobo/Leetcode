#include <string>
#include <algorithm>

using std::string;
using std::max;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        int left = 0;
        int right = 0;
        int nmax = 0;
        int count[26] = {0};
        int res = 0;
        while ( right < len ) {
            ++count[s[right] - 'A'];
            nmax = max(nmax, count[s[right] - 'A']);
            while ( right - left + 1 - nmax > k ) {
                --count[s[left++] - 'A'];
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
