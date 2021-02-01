#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = accumulate(A.begin(), A.end(), 0);
        int sum2 = accumulate(B.begin(), B.end(), 0);
        unordered_set<int> s(A.begin(), A.end());
        int detal = (sum1 - sum2) / 2;
        vector<int> res(2, 0);
        for ( int num2 : B ) {
            int num1 = detal + num2;
            if ( s.find(num1) != s.end() ) {
                res[0] = num1;
                res[1] = num2;
                break;
            }
        }
        return res;
    }
};
