#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // 0: 翻转奇数次不用再翻转，翻转偶数次需要再翻转
        // 1: 翻转偶数次不用再翻转，翻转奇数次需要再翻转
        int len = A.size(), count = 0;
        queue<int> que;
        for ( int i = 0; i < len; ++i ) {
            if ( !que.empty() && i >= que.front() + K ) {
                que.pop();
            }
            if ( que.size() % 2 == A[i] ) {
                if ( i + K > len ) return -1;
                que.push(i);
                ++count;
            }
        }
        return count;
    }
};
