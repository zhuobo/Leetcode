#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX / 2));
        for ( int i = 0; i < n; ++i ) {
            distance[i][i] = 0;
        }
        for ( const auto& edge : edges ) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        for ( int k = 0; k < n; ++k ) {
            for ( int i = 0; i < n; ++i ) {
                for ( int j = 0; j < n; ++j ) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        vector<int> count(n, 0);
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( i != j && distance[i][j] <= distanceThreshold ) {
                    ++count[i];
                }
            }
        }
        int min_count = n;
        for ( int i = 0; i < n; ++i ) {
            if ( count[i] <= min_count ) {
                min_count = count[i];
            }
        }
        int ret = -1;
        for ( int i = n - 1; i >= 0; --i ) {
            if ( count[i] == min_count ) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};
