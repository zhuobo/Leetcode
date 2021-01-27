#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

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
private:
    bool similar(string str1, string str2) {
        if ( str1 == str2 ) return true;
        int n = str1.size();
        int i = 0, j = n - 1;
        while ( i < n && str1[i] == str2[i] ) ++i;
        while ( j >=0 && str1[j] == str2[j] ) --j;
        swap(str1[i], str1[j]);
        return str1 == str2;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UnionFind union_find(n);
        for ( int i = 0; i < n - 1; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                if ( similar(strs[i], strs[j]) ) {
                    union_find.Union(i, j);
                }
            }
        }
        return union_find.Count();
    }
};
