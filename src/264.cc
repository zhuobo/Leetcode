// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for ( int i = 1; i < n; ++i ) {
            int a1 = ugly[p2] * 2, a2 = ugly[p3] * 3, a3 = ugly[p5] * 5;
            ugly[i] = min(a1, min(a2, a3));
            if ( ugly[i] == a1 ) ++p2;
            if ( ugly[i] == a2 ) ++p3;
            if ( ugly[i] == a3 ) ++p5;
        }
        return ugly[n - 1];
    }
};
