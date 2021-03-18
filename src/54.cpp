#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col - 1, up = 0, down = row - 1;
        vector<int> res;
        while ( true ) {
            for ( int i = left; i <= right; ++i ) {
                res.push_back(matrix[up][i]);
            }
            if ( ++up > down ) break;

            for ( int i = up; i <= down; ++i ) {
                res.push_back(matrix[i][right]);
            }
            if ( --right < left ) break;

            for ( int i = right; i >= left; --i ) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up ) break;

            for ( int i = down; i >= up; --i ) {
                res.push_back(matrix[i][left]);
            }
            if ( ++left > right ) break;
        }
        return res;
    }
};
