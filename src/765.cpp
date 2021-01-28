#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n) : parent(n), rank(n, 1), count(n) {
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
        } else if ( rank[qroot] < rank[proot] ) {
            parent[qroot] = proot;
        } else {
            parent[proot] = qroot;
            ++rank[qroot];
        }
        --count;
    }

    bool Connected(int p, int q) {
        return Find(p) == Find(q);
    }

    int Count() {
        return count;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        UnionFind union_find(len / 2);
        for ( int i = 0; i < len; i += 2 ) {
            union_find.Union(row[i] / 2, row[i + 1] / 2);
        }
        return len / 2 - union_find.Count();
    }
};
