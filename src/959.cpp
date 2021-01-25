#include <iostream>
#include <vector>
#include <string>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int _count) : count(_count) {
        parent.resize(_count);
        rank.resize(_count, 1);
        for ( int i = 0; i < _count; ++i ) {
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
        --count;
    }

    bool Connected (int p, int q) {
        return Find(p) == Find(q);
    }

    int GetCount() const {
        return count;
    }
};


class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        UnionFind union_find(4 * N * N);
        for ( int i = 0; i < N; ++i ) {
            for ( int j = 0; j < N; ++j ) {
                int index = 4 * (i * N + j);
                if ( grid[i][j] == '/' ) {
                    union_find.Union(index + 0, index + 1);
                    union_find.Union(index + 2, index + 3);
                } else if ( grid[i][j] == ' ' ) {
                    union_find.Union(index + 0, index + 1);
                    union_find.Union(index + 0, index + 2);
                    union_find.Union(index + 0, index + 3);
                } else {
                    union_find.Union(index + 0, index + 2);
                    union_find.Union(index + 1, index + 3);
                }

                // cell in next row
                if ( i + 1 < N ) {
                    union_find.Union(index + 3, 4 * ((i + 1) * N + j));
                }
                // cell in next column
                if ( j + 1 < N ) {
                    union_find.Union(index + 2, index + 5);
                }
            }
        }
        return union_find.GetCount();
    }
};


int main() {
    Solution s;
    vector<string> grid = { "\\/", "/\\" };
    cout << s.regionsBySlashes(grid) << endl;
}
