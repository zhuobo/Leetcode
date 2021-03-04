#include <vector>
#include <algorithm>


using std::vector;
using std::sort;
using std::max;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2){
            return v1 <= v2;
        });
        int len = envelopes.size();
        vector<int> dp(len, 0);
        int res = 0;
        for ( int i = 0; i < len; ++i ) {
            dp[i] = 1;
            for ( int j = 0; j < i; ++j ) {
                if ( envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] ) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


// solution 2
class Solution2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
        });
        int len = envelopes.size();
        vector<vector<int>> dp;
        if ( len == 0 ) {
            return 0;
        }
        dp.emplace_back(envelopes[0]);
        for ( int i = 1; i < len; ++i ) {
            if ( strictly_greater(envelopes[i], dp.back()) ) {
                dp.emplace_back(envelopes[i]);
            } else {
                // binary search
                int left = 0, right = dp.size() - 1;
                while ( left <= right ) {
                    int mid = left + (right - left) / 2;
                    if ( strictly_greater(envelopes[i], dp[mid]) ) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                dp[left][0] = envelopes[i][0];
                dp[left][1] = envelopes[i][1];
            }
        }
        return dp.size();
    }

    inline bool strictly_greater(vector<int>& v1, vector<int>& v2) {
        return v1[0] > v2[0] && v1[1] > v2[1];
    }
};
