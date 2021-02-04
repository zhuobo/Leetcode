#include <vector>
using std::vector;

class Solution {
private:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& hasApple, int node, int mycost) {
        if  ( visited[node] ) {
            return 0;
        }
        visited[node] = true;
        int child_cost = 0;
        for ( int child : graph[node] ) {
            child_cost += dfs(graph, visited, hasApple, child, 2);
        }
        if ( child_cost == 0 && !hasApple[node] ) {
            return 0;
        }
        return child_cost + mycost;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n, vector<int>());
        for ( const auto& edge : edges ) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, hasApple, 0, 0);
    }
};
