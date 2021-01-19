#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(vector<vector<int>>& graph, unordered_set<int>& safe_node, int node) {
        if ( safe_node.find(node) != safe_node.end() ) {
            return true;
        }
        for ( int next_node : graph[node] ) {
            if ( dfs(graph, safe_node, next_node) ) {
                return true;
            }
        }
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // graph is a adjacency list
        int n = graph.size();
        unordered_set<int> safe_node;
        for ( int i = 0; i < n; ++i ) {
            if ( graph[i].empty() ) {
                safe_node.insert(i);
            }
        }
        
        vector<int> res;
        for ( int i = 0; i < n; ++i ) {
            if ( dfs(graph, safe_node, i) ) {
                res.push_back(i);
            }
        }
        return res;
    }
};
