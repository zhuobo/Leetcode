#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<int> count1(26, 0), count2(26, 0);
        for ( char c : s1 ) {
            ++count1[c - 'a'];
        }
        for ( int i = 0; i < len2; ++i ) {
            ++count2[s2[i] - 'a'];
            if ( i >= len1 ) {
                --count2[s2[i - len1] - 'a'];
            }
            if ( i >= len1 - 1 && count1 == count2 ) {
                return true;
            } 
        }
        return false;
    }
};
