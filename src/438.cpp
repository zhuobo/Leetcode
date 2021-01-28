#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // vector in STL has overload operator==
        vector<int> countp(26, 0), counts(26, 0);
        vector<int> res;
        int len_s = s.size(), len_p = p.size();
        if ( len_s < len_p ) return res;
        for ( char c : p ) {
            ++countp[c - 'a'];
        }
        for ( int i = 0; i < len_s; ++i ) {
            // move the next character into window
            ++counts[s[i] - 'a'];
            // move the left most character out of the window
            if ( i >= len_p ) {
                --counts[s[i - len_p] - 'a'];
            }
            // anagram has the same length
            if ( i >= len_p - 1 && counts == countp ) {
                res.push_back(i - len_p + 1);
            }
        }
        return res;
    }
};
