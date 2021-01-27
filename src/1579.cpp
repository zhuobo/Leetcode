#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int n) : parent(n), rank(n, 1), count(n) {
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
        --count;
    }

    bool Connected(int p, int q) {
        int proot = Find(p), qroot = Find(q);
        return proot == qroot;
    }

    int Count() {
        return count;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind union_find1(n + 1), union_find2(n + 1); 
        int edge_need[4] = { 0 };
        for (  const auto& edge : edges ) {
            int type = edge[0];
            if ( type == 3 ) {
                int from = edge[1], to = edge[2];
                if ( !union_find1.Connected(from, to) && !union_find2.Connected(from, to) ) {
                    union_find1.Union(from, to);
                    union_find2.Union(from, to);
                    ++edge_need[3];
                } else if ( !union_find1.Connected(from, to) ) {
                    union_find1.Union(from, to);
                    ++edge_need[3];
                } else if ( !union_find2.Connected(from, to) ) {
                    union_find2.Union(from, to);
                    ++edge_need[3];
                }
            }
        }
        for ( const auto& edge : edges ) {
            int type = edge[0];
            if ( type == 1 ) {
                int from = edge[1], to = edge[2];
                if ( !union_find1.Connected(from, to) ) {
                    union_find1.Union(from, to);
                    ++edge_need[1];
                }
            }
        }
        for ( const auto& edge : edges ) {
            int type = edge[0];
            if ( type == 2 ) {
                int from = edge[1], to = edge[2];
                if ( !union_find2.Connected(from, to) ) {
                    union_find2.Union(from, to);
                    ++edge_need[2];
                }
            }
        }
        int set_count1 = union_find1.Count() - 1, set_count2 = union_find2.Count() - 1;
        if ( set_count1 == 1 && set_count2 == 1 ) {
            return edges.size() - edge_need[1] - edge_need[2] - edge_need[3];
        }
        return -1;
    }
};
