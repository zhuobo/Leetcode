#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for ( auto& ivec : A) {
            reverse(ivec.begin(), ivec.end());
            for ( int i = 0; i < ivec.size(); ++i ) {
                ivec[i] = 1 - ivec[i];
            }
        }
        return A;
    }
};
