#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> colors(n, 0);
        vector<vector<int>> adjacency(n + 1, vector<int>());
        for ( const auto& path : paths ) {
            adjacency[path[0]].push_back(path[1]);
            adjacency[path[1]].push_back(path[0]);
        }
        // find all the color that adjacent node used
        for ( int i = 1; i <= n; ++i ) {
            vector<bool> color_used(5, false);
            for ( int j : adjacency[i] ) {
                if ( colors[j - 1] != 0 ) {
                    color_used[colors[j - 1]] = true;
                }
            }
            // color not used can use to paint current node i
            for ( int color = 1; color <= 4; ++color ) {
                if ( !color_used[color] ) {
                    colors[i - 1] = color;
                    break;
                }
            }
        }
        return colors;
    }
};
