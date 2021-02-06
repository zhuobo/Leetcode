#include <vector>
#include <climits>
#include <numeric>
#include "structure.h"

using namespace std;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int left = len - k, right = len - 1;
        int cur_sum = accumulate(cardPoints.begin() + left, cardPoints.begin() + right + 1, 0);
        int max_sum = cur_sum;
        right = 0;
        while ( right < k ) {
            cur_sum += cardPoints[right++] - cardPoints[left++];
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};

class Solution2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        // windows size len - k
        int cur_sum = accumulate(cardPoints.begin(), cardPoints.begin() + (len - k), 0);
        int min_sum = cur_sum;
        for ( int i = len - k; i < len; ++i ) {
            cur_sum += cardPoints[i] - cardPoints[i - (len - k)];
            min_sum = min(min_sum, cur_sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_sum;
    }
};


class Solution3 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> presum(k + 1, 0), postsum(k + 1, 0);
        for ( int i = 1; i <= k; ++i ) {
            presum[i] += presum[i - 1] + cardPoints[i - 1];
            postsum[i] += postsum[i - 1] + cardPoints[len - i];
        }
        int max_sum = INT_MIN;
        for ( int i = 0; i <= k; ++i ) {
            max_sum = max(max_sum, presum[i] + postsum[k - i]);
        }
        return max_sum;
    }
};
