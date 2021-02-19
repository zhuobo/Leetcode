#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size(), max_len = 0;
        int left = 0, right = 0, zero_count = 0;
        while ( right < len ) {
            zero_count += 1 - A[right];
            while ( zero_count > K ) {
                zero_count -= 1 - A[left++];
            }
            max_len = max(max_len, right - left + 1);
            ++right;
        }
        return max_len;
    }
};
