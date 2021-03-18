#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = customers.size();
        if ( grumpy.empty() ) return 0;
        int not_grumpy = 0, cur_grumpy = 0, max_grumpy = 0;
        for ( int i = 0; i < len; ++i ) {
            if ( grumpy[i] == 0 ) {
                not_grumpy += customers[i];
            } else {
                cur_grumpy += customers[i];
            }
            if ( i >= X && grumpy[i - X] == 1 ) {
                cur_grumpy -= customers[i - X];
            }
            max_grumpy = max(max_grumpy, cur_grumpy);
        }
        return not_grumpy + max_grumpy;
    }
};
