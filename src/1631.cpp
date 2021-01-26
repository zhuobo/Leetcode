#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>

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

class Solution2 {
private:
    static constexpr int dirs[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

    // 判断是否有一条路径从起点到终点
    bool connected(vector<vector<int>>& heights, int cost) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> que;
        que.emplace(0, 0);
        visited[0][0] = true;
        while ( !que.empty() ) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for ( int i = 0; i < 4; ++i ) {
                int new_x = x + dirs[i][0], new_y = y + dirs[i][1];
                if ( new_x >= 0 && new_x < row && new_y >= 0 && new_y < col ) {
                    if ( !visited[new_x][new_y] && abs(heights[x][y] - heights[new_x][new_y]) <= cost ) {
                        que.emplace(new_x, new_y);
                        visited[new_x][new_y] = true;
                        if ( new_x == row - 1 && new_y == col - 1 ) {
                            break;
                        }
                    }
                }
            }
        }
        return visited[row - 1][col - 1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // binary search
        int left = 0, right = 999999;
        while ( left < right ) {
            int mid = left + ( right - left ) / 2;
            if (  connected(heights, mid) ) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
