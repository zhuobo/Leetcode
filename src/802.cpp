#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
        // 0: not visited; 1: visiting; 2: visited
        if ( visited[node] == 2 ) {
            return true;
        } else if ( visited[node] == 1 ) {
            return false;
        } else {
            // 将要访问当前节点，将当前节点置为正在访问状态
            // 如果在这一轮访问中，又访问到了这种正在访问状态的节点，
            // 那么就能说明存在环
            visited[node] = 1;
            for ( const auto& next_node : graph[node] ) {
                if ( !dfs(graph, visited, next_node) ) {
                    return false;
                } }
            // 否则，这个节点不会进入某个环中
            visited[node] = 2;
        }
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // graph is a adjacency list
        int n = graph.size();
        vector<int> safe_nodes;
        vector<int> visited(n, 0);
        for ( int i = 0; i < n; ++i ) {
            if ( dfs(graph, visited, i) ) {
                safe_nodes.push_back(i);
            }
            visited.resize(n, 0);
        }
        return safe_nodes;
    }
};
