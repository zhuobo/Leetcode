#include <vector>
using std::vector;

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
    int N;
    static constexpr int dirs[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    int get_index(int x, int y) {
        return x * row + y;
    }

    bool ingrid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N; 
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int size = N * N;
        UnionFind union_find(size());
        // index[i] is the index of height i
        vector<int> index(size);
        for ( int i = 0; i < N; ++i ) {
            for ( int j = 0; j < N; ++j ) {
                index[grid[i][j]] = get_index(i, j);
            }
        }

        for ( int i = 0; i < size; ++i ) {
            int x = index[i] / N, y = index[i] % N;
            for ( int j = 0; j < 4; ++j ) {
                int new_x = x + dirs[j][0], new_y = y + dirs[j][1];
                if ( ingrid(new_x, new_y) && grid[new_x][new_y] <= i ) {
                    union_find.Union(index[i], get_index(new_x, new_y));
                }
                if ( union_find.Connected(0, size - 1) ) {
                    return i;
                }
            }

        }
        return -1;
    }
};
