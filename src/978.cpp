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
