#include <vector>
#include <numeric>

using namespace  std;

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
