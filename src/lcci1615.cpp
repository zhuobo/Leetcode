#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> res(2, 0);
        int count1[26] = { 0 };
        int count2[26] = { 0 };
        for ( int i = 0; i < 4; ++i ) {
            if ( solution[i] == guess[i] ) {
                ++res[0];
            } else {
                ++count1[solution[i] - 'A'];
                ++count2[guess[i] - 'A'];
            }
        }
        res[1] = min(count1['R' - 'A'], count2['R' - 'A'])
               + min(count1['G' - 'A'], count2['G' - 'A'])
               + min(count1['B' - 'A'], count2['B' - 'A'])
               + min(count1['Y' - 'A'], count2['Y' - 'A']);
        return res;
    }
};
