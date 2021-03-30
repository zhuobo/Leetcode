// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.30
// Filename:        74.cpp
// Descripton:       

#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row * col - 1;
        int mid = -1;
        while ( left <= right ) {
            mid = left + (right - left) / 2;
            if ( target == matrix[mid / col][mid % col] ) {
                return true;
            } else if ( target > matrix[mid / col][mid % col] ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
