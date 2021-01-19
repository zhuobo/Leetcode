#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// solution1: BFS
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> adjacency(n, vector<int>());
        for ( const auto& edge : graph ) {
            int from = edge[0], to = edge[1];
            adjacency[from].push_back(to);
        }
        bool has_path = false;
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(start);
        visited[start] = true;
        while ( !que.empty() ) {
            int cur_node = que.front();
            que.pop();
            if ( cur_node == target ) {
                has_path = true;
                break;
            }
            for ( int next_node : adjacency[cur_node] ) {
                if ( !visited[next_node] ) {
                    que.push(next_node);
                    visited[next_node] = true;
                }
            }
        }
        return has_path;
    }
};

// solution2: DFS
class Solution2 {
private:
    bool dfs(vector<vector<int>>& adjacency, int start, int target) {
        if ( start == target ) {
            return true;
        }
        for ( int next_node : adjacency[start] ) {
            if ( dfs(adjacency, next_node, target) ) {
                return true;
            }
        }
        return false;
    }
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> adjacency(n, vector<int>());
        for ( const auto& edge : graph ) {
            adjacency[edge[0]].push_back(edge[1]);
        }
        return dfs(adjacency, start, target);
    }
};
