#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// solution1: Floyd
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX / 2));
        for ( int i = 0; i < n; ++i ) {
            distance[i][i] = 0;
        }
        for ( const auto& edge : edges ) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        for ( int k = 0; k < n; ++k ) {
            for ( int i = 0; i < n; ++i ) {
                for ( int j = 0; j < n; ++j ) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        vector<int> count(n, 0);
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( i != j && distance[i][j] <= distanceThreshold ) {
                    ++count[i];
                }
            }
        }
        int min_count = n;
        for ( int i = 0; i < n; ++i ) {
            if ( count[i] <= min_count ) {
                min_count = count[i];
            }
        }
        int ret = -1;
        for ( int i = n - 1; i >= 0; --i ) {
            if ( count[i] == min_count ) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};

// solution2: dijkstra
class Solution2 {
private:
    typedef pair<int, int> PII;

    vector<int> dijkstra(vector<vector<PII>>& graph, int node) {
        int n = graph.size();
        priority_queue<PII, vector<PII>, greater<PII>> que;
        vector<int> distance(n, INT_MAX / 2);
        distance[node] = 0;
        que.emplace(0, node);
        while ( !que.empty() ) {
            int cur_weight = que.top().first;
            int cur_node   = que.top().second;
            que.pop();
            for ( const auto& p : graph[cur_node] ) {
                int next_weight = p.second, next_node = p.first;
                if ( cur_weight + next_weight < distance[next_node] ) {
                    distance[next_node] = cur_weight + next_weight;
                    que.emplace(distance[next_node], next_node);
                }
            }
        }
        return distance;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<PII>> graph(n, vector<PII>());
        for ( const auto& edge : edges ) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].emplace_back(to, weight);
            graph[to].emplace_back(from, weight);
        }
        vector<int> count(n, 0);
        for ( int i = 0; i < n; ++i ) {
            vector<int> distance = dijkstra(graph, i);
            for ( int j = 0; j < n; ++j ) {
                if ( j != i && distance[j] <= distanceThreshold ) {
                    ++count[i];
                }
            }
        }
        int min_count = n;
        for ( int i = 0; i < n; ++i ) {
            if ( count[i] <= min_count ) {
                min_count = count[i];
            }
        }
        int ret = -1;
        for ( int i = n - 1; i >= 0; --i ) {
            if ( count[i] == min_count ) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};
