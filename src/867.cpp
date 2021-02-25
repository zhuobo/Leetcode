#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        vector<vector<int>> res(col, vector<int>(row));
        for ( int i = 0; i < row; ++i ) {
            for ( int j = 0; j < col; ++j ) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};
