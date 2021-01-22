#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Union Find Set
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
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
        } else if ( rank[qroot] < proot ) {
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

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n_val = 0;
        unordered_map<char, int> char_int;
        for ( const string& equation : equations ) {
            char c1 = equation[0], c2 = equation[3];
            if ( char_int.find(c1) == char_int.end() ) {
                char_int[c1] = n_val++;
            }
            if ( char_int.find(c2) == char_int.end() ) {
                char_int[c2] = n_val++;
            }
        }
        UnionFind union_find(n_val);
        // union all char connected by "=="
        for ( const string& equation : equations ) {
            if ( equation[1] == '!' ) {
                continue;
            }
            int symbol1 = char_int[equation[0]], symbol2 = char_int[equation[3]];
            union_find.Union(symbol1, symbol2);
        }
        // judge all char connected by "!="
        for ( const string& equation : equations ) {
            if ( equation[1] == '=' ) {
                continue;
            }
            int symbol1 = char_int[equation[0]], symbol2 = char_int[equation[3]];
            if ( union_find.Connected(symbol1, symbol2) ) {
                return false;
            }
        }
        return true;
    }
};

