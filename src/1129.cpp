#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
class Solution {
private:
    typedef pair<int, int>   PII;
    static constexpr int     RED   = 0;
    static constexpr int     BLUE  = 1;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res(n, -1);
        // 0: color red; 1: color: blue
        vector<vector<PII>> graph(n, vector<PII>());
        vector<vector<bool>> visited(n, vector<bool>());
        for ( const auto& edge : red_edges ) {
            graph[edge[0]].emplace_back(edge[1], RED);
            visited[edge[0]].push_back(false);
        }
        for ( const auto& edge : blue_edges ) {
            graph[edge[0]].emplace_back(edge[1], BLUE);
            visited[edge[0]].push_back(false);
        }
        queue<PII> que;
        int step = 0;
        res[0] = step;
        ++step;
        for ( int i = 0; i < graph[0].size(); ++i ) {
            int next_node = graph[0][i].first;
            int next_color = graph[0][i].second;
            que.emplace(next_node, next_color);
            // So Disgusting!! use case: [0, 0]
            if ( next_node == 0 ) {
                continue;
            }
            visited[0][i] = true;
            res[next_node] = step;
        }
        ++step;
        while ( !que.empty() ) {
            int size = que.size();
            while ( size-- ) {
                int cur_node  = que.front().first;
                int cur_color = que.front().second;
                que.pop();
                for ( int i = 0; i < graph[cur_node].size(); ++i ) {
                    int next_node = graph[cur_node][i].first;
                    int next_color = graph[cur_node][i].second;
                    if ( !visited[cur_node][i] && next_color != cur_color ) {
                        if ( res[next_node] == -1 ) res[next_node] = step;
                        que.emplace(next_node, next_color);
                        visited[cur_node][i] = true;
                    }
                }
            }
            ++step;
        }
        return res;
    }
};
