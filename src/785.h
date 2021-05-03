// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       
#ifndef SRC_785_H
#define SRC_785_H

#include "union_find.h"
#include <vector>

using std::vector;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        UnionFind union_find(n);
        for ( int i = 0; i < n; ++i ) {
            for ( int j : graph[i] ) {
                if ( union_find.Connected(i, j) ) {
                    return false;
                }
                union_find.Union(graph[i][0], j);
            }
        }
        return true;
    }
};

#endif 
