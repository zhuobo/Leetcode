#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

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


class Solution2 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rgraph(n, vector<int>());
        vector<int> indegree(n, 0);
        for ( int i = 0; i < n; ++i ) {
            for ( int j : graph[i] ) {
                rgraph[j].push_back(i);
                ++indegree[i];
            }
        }
        queue<int> que;
        for ( int i = 0; i < n; ++i ) {
            if ( indegree[i] == 0 ) {
                que.push(i);
            }
        }
        vector<int> safe_nodes;
        while ( !que.empty() ) {
            int cur_node = que.front();
            que.pop();
            safe_nodes.push_back(cur_node);
            for ( int next_node : rgraph[cur_node] ) {
                if ( --indegree[next_node] == 0 ) {
                    que.push(next_node);
                }
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};
