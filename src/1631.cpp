#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int Find(int p) {
        if ( parent[p] != p ) {
            parent[p] = Find(parent[p]);
        }
        return parent[p];
    }

    void Union(int p, int q) {
        int proot = Find(p), qroot = Find(q);
        if ( proot == qroot ) {
            return;
        }
        if ( rank[proot] < rank[qroot] ) {
            parent[proot] = qroot;
        } else if ( rank[qroot] < rank[proot] ) {
            parent[qroot] = proot;
        } else {
            parent[proot] = qroot;
            ++rank[qroot];
        }
    }

    bool Connected(int p, int q) {
        return Find(p) == Find(q);
    }
};

struct Edge {
    int from, to, distance;

    Edge(int _from, int _to, int _distance)
        : from(_from), to(_to), distance(_distance) {  }
    
    bool operator<(const Edge& rhs) const {
        return distance < rhs.distance;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<Edge> edges;
        int cur_index = -1, next_index = -1, weight = 0;
        for ( int i = 0; i < row; ++i ) {
            for ( int j = 0; j < col; ++j ) {
                cur_index = i * col + j;
                if ( j + 1 < col ) {
                    next_index = cur_index + 1;
                    weight = abs(heights[i][j] - heights[i][j + 1]);
                    edges.emplace_back(cur_index, next_index, weight);
                    edges.emplace_back(next_index, cur_index, weight);
                }
                if ( i + 1 < row ) {
                    next_index = (i + 1) * col + j;
                    weight = abs(heights[i][j] - heights[i + 1][j]);
                    edges.emplace_back(cur_index, next_index, weight);
                    edges.emplace_back(next_index, cur_index, weight);
                }
            }
        }

        sort(edges.begin(), edges.end());
        UnionFind union_find(row * col);
        for ( const auto& edge : edges ) {
            int from = edge.from, to = edge.to, weight = edge.distance;
            if (  !union_find.Connected(0, row * col - 1) ) {
                union_find.Union(from, to);
            } else {
                return weight;
            }
        }
        return 0; 
    }
};
