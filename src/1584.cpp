// 1584:  the cost of minimum spanning tree 
// Solution1: kruskal
// Solution2: Prim

#include <iostream>
#include <vector>

using namespace std;


// Solutin1: Kruskal algorithm
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank   = vector<int>(n, 1);
        for ( int i = 0; i < n; ++i ) {
            parent[i] = i;
        }
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

    bool connected(int p, int q) {
        return Find(p) == Find(q);
    }
};

// the edge between node x and node y
struct edge {
    int x, y, dist;
    edge(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {  }
};

class Solution {
private:
    // the distance between node i and j
    int distance(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        UnionFind union_find(len);
        vector<edge> edges;
        for ( int i = 0; i < len - 1; ++i ) {
            for ( int j = i + 1; j < len; ++j ) {
                edges.emplace_back(i, j, distance(points, i, j));
            }
        }
        sort(edges.begin(), edges.end(), [](edge& e1, edge& e2){
            return e1.dist < e2.dist;
        });
        int min_cost = 0, node_count = 1;
        for ( edge& e : edges ) {
            int x = e.x, y = e.y, dist = e.dist;
            if ( !union_find.connected(x, y) ) {
                union_find.Union(x, y);
                min_cost += dist;
                ++node_count;
                if ( node_count == len ) {
                    break;
                }
            }
        }
        return min_cost;
    }
};
