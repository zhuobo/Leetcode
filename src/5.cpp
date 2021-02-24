#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int max_len = 1, start = 0;
        for ( int i = 0; i < len; ++i ) {
            dp[i][i] = true;
        }
        for ( int j = 1; j < len; ++j ) {
            for ( int i = 0; i < j; ++i ) {
                if ( s[i] == s[j] ) {
                    if ( i + 1 == j || j + 2 == j ) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                } else {
                    dp[i][j] = false;
                }
                if ( dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }
};
