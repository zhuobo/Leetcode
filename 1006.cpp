#include <iostream>


class Solution {
public:
    int clumsy(int N) {
        if ( N == 1 ) {
            return 1;
        } else if ( N == 2 ) {
            return 2;
        } else if ( N == 3 ) {
            return 6;
        }
        int res = N * (N - 1) / (N - 2) + ( N - 3);
        // cout << res << endl;
        int i = N - 4;   
        while ( i >= 1 ) {
            int curr = i;
            --i;
            if ( i >= 1 ) {
                curr *= i;
            }
            --i;
            if ( i >= 1 ) {
                curr /= i;
            }
            // cout << curr << endl;
            res -= curr;
            --i;
            if ( i >= 1 ) {
                res += i;
            }
            --i;
        }
        return res;
    }
};


int main() {
    Solution s;
    std::cout << s.clumsy(1778) << std::endl;
}
