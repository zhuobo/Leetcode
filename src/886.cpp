#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
// Union Find Set
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    // Init
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for ( int i = 0; i < n; ++i ) {
            parent[i] = i;
        }
    }
    // Find, path compression
    int Find(int p) {
        if ( parent[p] != p ) {
            parent[p] = Find(parent[p]);
        }
        return parent[p];
    }
    // Union by rank
    void Union(int p, int q) {
        int proot = Find(p), qroot = Find(q);
        if ( proot == qroot ) {
            return;
        }
        if ( rank[proot] < rank[qroot] ) {
            parent[proot] = qroot;
        } else if (rank[qroot] < rank[proot] ) {
            parent[qroot] = proot;
        } else {
            parent[proot] = qroot;
            ++rank[qroot];
        }
    }
    // Connected?
    bool Connected(int p, int q) {
        return Find(p) == Find(q);
    }
};

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        UnionFind union_find(N + 1);
        vector<vector<int>> adjacency(N + 1, vector<int>());
        for ( const auto& dislike : dislikes ) {
            adjacency[dislike[0]].push_back(dislike[1]);
            adjacency[dislike[1]].push_back(dislike[0]);
        }
        bool two_part = true;
        // union all enemy together
        for ( int i = 1; i <= N; ++i ) {
            if ( !adjacency[i].empty() ) {
                if ( union_find.Connected(i, adjacency[i][0] ) ) {
                    two_part = false;
                    break;
                }
                for ( int j : adjacency[i] ) {
                    if ( union_find.Connected(i, j) ) {
                        two_part = false;
                        break;
                    } else {
                        union_find.Union(j, adjacency[i][0]);
                    }
                }
            }
        }
        return two_part;
    }
};

// BFS color
class Solution2 {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // 0: not visited; 1 : color black; -1 color red;
        vector<int> color(N + 1, 0);
        vector<vector<int>> adjacency(N + 1, vector<int>());
        for ( const auto& dislike : dislikes ) {
            adjacency[dislike[0]].push_back(dislike[1]);
            adjacency[dislike[1]].push_back(dislike[0]);
        }
        queue<int> que;
        for ( int i = 1; i <= N; ++i ) {
            if ( color[i] != 0 ) {
                continue;
            }
            que.push(i);
            int cur_color = 1;
            color[i] = cur_color;
            while ( !que.empty() ) {
                int cur_node = que.front();
                que.pop();
                cur_color = color[cur_node];
                int next_color = -cur_color;
                for ( int next_node : adjacency[cur_node] ) {
                    if ( color[next_node] == cur_color ) {
                        return false;
                    } else if ( color[next_node] == 0 ) {
                        color[next_node] = next_color;
                        que.push(next_node);
                    }
                }
            }
        }
        return true;
    }
};
