#include <string>
#include <algorithm>
#include <climits>

using std::string;
using std::reverse;
using std::to_string;
using std::swap;

class Solution {
public:
    int nextGreaterElement(int n) {
        string max_int = to_string(INT_MAX);
        string str     = to_string(n);
        
        int i = str.size() - 1;
        while ( i >= 1 && str[i] <= str[i - 1] ) --i;
        // 递减的，没有更大的了
        if ( i == 0 ) return -1;
        int j = i - 1;
        int k = str.size() - 1;
        while ( str[k] <= str[j] ) --k;
        swap(str[k], str[j]);
        reverse(str.begin() + i, str.end());
        return (str.size() > max_int.size())
            || (str.size() == max_int.size() && str > max_int)
            ?
            -1 : stoi(str);
    }
};
