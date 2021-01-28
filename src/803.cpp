#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int count;
public:
    UnionFind(int n) : parent(n), rank(n, 1), size(n, 1), count(n) {
        std::iota(parent.begin(), parent.end(), 0);
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
            size[qroot] += size[proot];
        } else if ( rank[qroot] < rank[proot] ) {
            parent[qroot] = proot;
            size[proot] += size[qroot];
        } else {
            parent[proot] = qroot;
            ++rank[qroot];
            size[qroot] += size[proot];
        }
        --count;
    }

    bool Connected(int p, int q) {
        return Find(p) == Find(q);
    }

    int Count() {
        return count;
    }

    int Size(int p) {
        return size[Find(p)];
    }
};


class Solution {
private:
    static constexpr int dirs[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    
    int get_index(int i, int j) {
        return i * col + j;
    }

    bool in_grid(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    int row;
    int col;
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<int>> copy(row, vector<int>(col));
        for ( int i = 0; i < row; ++i ) {
            for ( int j = 0; j < col; ++j ) {
                copy[i][j] = grid[i][j];
            }
        }
        for ( const auto& hit : hits ) {
            copy[hit[0]][hit[1]] = 0;
        }

        int len  = row * col;
        // size is root in union find
        // union bricks in the first with the root
        UnionFind union_find(len + 1);
        for ( int j = 0; j < col; ++j ) {
            if ( copy[0][j] == 1 ) {
                union_find.Union(j, len);
            }
        }

        for ( int i = 1; i < row; ++i ) {
            for ( int j = 0; j < col; ++j ) {
                if ( copy[i][j] == 1 ) {
                    if ( copy[i - 1][j] == 1 ) {
                        union_find.Union(get_index(i, j), get_index(i - 1, j));
                    }
                    if ( j > 0 && copy[i][j - 1] == 1 ) {
                        union_find.Union(get_index(i, j), get_index(i, j - 1));
                    }
                }
            }
        }

        int hits_len = hits.size();
        vector<int> brick_drop_count(hits_len, 0);
        for ( int i = hits_len - 1; i >= 0; --i ) {
            int x = hits[i][0], y = hits[i][1];
            if ( grid[x][y] == 0 ) {
                continue;
            }
            int origin_stable = union_find.Size(len);
            if ( x == 0 ) {
                union_find.Union(y, len);
            }
            for ( int i = 0; i < 4; ++i ) {
                int new_x = x + dirs[i][0], new_y = y + dirs[i][1];
                if ( in_grid(new_x, new_y) && copy[new_x][new_y] == 1 ) {
                    union_find.Union(get_index(x, y), get_index(new_x, new_y));
                }
            }

            int new_stable = union_find.Size(len);
            brick_drop_count[i] = max(0, new_stable - origin_stable - 1);
            copy[x][y] = 1;
        }
        return brick_drop_count;
    }
};
