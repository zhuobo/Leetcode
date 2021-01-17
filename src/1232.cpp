#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        int len = coordinates.size();
        const double epsilon = 0.000001;
        if ( x0 == x1 ) {
            for ( int i = 2; i < len; ++i ) {
                int x = coordinates[i][0], y = coordinates[i][1];
                if ( x != x0 ) {
                    return false;
                }
            }
        } else {
            double slope = (y1 - y0) * 1.0 / (x1 - x0);         
            for ( int i = 2; i < len; ++i ) {
                int x = coordinates[i][0], y = coordinates[i][1];
                if ( x == x0 || x == x1 ) {
                    return false;
                } else {
                    double cur_slope = (y - y0) * 1.0 / (x - x0);
                    if ( abs(slope - cur_slope) > epsilon ) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
