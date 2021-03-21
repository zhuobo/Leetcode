// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.21
// Filename:        73.cpp
// Descripton:      https://leetcode-cn.com/problems/set-matrix-zeroes/

#include <vector>

using std::vector;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        bool row0_has_zero = false;
        bool col0_has_zero = false;
        for ( int j = 0; j < col; ++j ) {
            if ( matrix[0][j] == 0 ) {
                row0_has_zero = true;
                break;
            }
        }
        for ( int i = 0; i < row; ++i ) {
            if ( matrix[i][0] == 0 ) {
                col0_has_zero = true;
                break;
            }
        }
        for ( int i = 1; i < row; ++i ) {
            for ( int j = 1; j < col; ++j ) {
                if ( matrix[i][j] == 0 ) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for ( int i = 1; i < row; ++i ) {
            for ( int j = 1; j < col; ++j ) {
                if ( matrix[0][j] == 0 || matrix[i][0] == 0 ) {
                    matrix[i][j] = 0;
                }
            }
        }
        if ( row0_has_zero ) {
            for ( int j = 0; j < col; ++j ) {
                matrix[0][j] = 0;
            }
        }
        if ( col0_has_zero ) {
            for ( int i = 0; i < row; ++i ) {
                matrix[i][0] = 0;
            }
        }
    }
};



