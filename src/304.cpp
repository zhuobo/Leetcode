#include <vector>

using std::vector;

class NumMatrix {
    vector<vector<int>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if ( !matrix.empty() ) {
            int row = matrix.size(), col = matrix[0].size();
            presum.resize(row, vector<int>(col + 1, 0));
            for ( int i = 0; i < row; ++i ) {
                for ( int j = 1; j <= col; ++j ) {
                    presum[i][j] = presum[i][j - 1] + matrix[i][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        if ( presum.empty() ) return 0;
        for ( int i = row1; i <= row2; ++i ) {
            res += presum[i][col2 + 1] - presum[i][col1]; 
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
