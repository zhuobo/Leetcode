#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        int left = 0;
        int cur_len = 0, max_len = 0;
        int prev, curr;
        bool up;
        while ( left < len ) {
            if ( left == len - 1 ) {
                max_len = max(max_len, 1);
                break;
            }
            prev = left;
            curr = left + 1;
            if ( arr[prev] == arr[curr] ) {
                ++left;
                continue;
            } else {
                up = arr[curr] > arr[prev] ? true : false;
            }
            ++curr; ++prev;
            while ( curr < len ) {
                if ( arr[curr] == arr[prev] ) {
                    max_len = max(max_len, curr - left);
                    break;
                } else if ( arr[curr] < arr[prev] ) {
                    if ( up ) {
                        ++prev; ++curr;
                        up = !up;
                    } else {
                        max_len = max(max_len, prev - left);
                        break;
                    }
                } else {
                   if ( up ) {
                       max_len = max(max_len, prev - left);
                       break;
                   } else {
                       ++prev; ++curr;
                       up = !up;
                   }
                }
            }
            max_len = max(max_len, curr - left);
            left = prev;
        }
        return max_len;
    }
};


class Solution2 {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        int up = 1, down = 1, max_len = 1;
        for ( int i = 1; i < len; ++i ) {
            if ( arr[i] == arr[i - 1] ) {
                up = down = 1;
            } else if ( arr[i] > arr[i - 1] ) {
                up = down + 1;
                down = 1;
            } else {
                down = up + 1;
                up = 1;
            }
            max_len = max(max_len, max(up, down));
        }
        return max_len;
    }
};
