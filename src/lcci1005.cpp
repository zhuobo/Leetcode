#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int len = words.size();
        for ( int i = 0; i < len; ++i ) {
            if ( words[i] == s ) {
                return i;
            }
        }
        return -1;
    }
};


class Solution2 {
public:
    int findString(vector<string>& words, string s) {
        int len = words.size();
        int left = 0;
        int right = len - 1;
        while ( left <= right ) {
            int mid = left + (right - left) / 2;
            int temp = mid;
            while ( words[mid].empty() && mid < right ) {
                ++mid;
            }
            if ( words[mid].empty() ) {
                right = temp - 1;
                continue;
            }
            if ( words[mid] == s ) {
                return mid;
            } else if ( words[mid] < s ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};      
