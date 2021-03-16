#include <vector>

using std::vector;

// solution 1
class Solution {
private:
    int count(int num) {
        int res = 0;
        while ( num != 0 ) {
            res += (num & 1);
            num = num >> 1;
        }
        return res;
    }
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for ( int i = 0; i <= num; ++i ) {
            res[i] = count(i);
        }
        return res;
    }
};

// solution 2
class Solutions {
public:
    vector<int> countBits(int num) {
        vector<int> counts(num + 1, 0);
        // counts[i + b] = counts[i] + 1 where i < b && b = 2 ^ m
        int i = 0, b = 1;
        while ( b <= num ) {
            while ( i < b && i + b <= num ) {
                counts[i + b] = counts[i] + 1;
                ++i;
            }
            i = 0;
            b <<= 1;
        }
        return counts;
    }
};
