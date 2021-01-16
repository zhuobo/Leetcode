// https://leetcode-cn.com/problems/network-delay-time/
// This is a Single Source Shortest Path(SSSP) problem. Dijkstra algorithm is 
// used to solve this problem
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
private:
    typedef pair<int, int> PII;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> adjacent(n + 1);
        for ( const auto& time : times ) {
            int from = time[0], to = time[1], weight = time[2];
            adjacent[from].emplace_back(to, weight);
        }
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> que;
        que.emplace(0, k);
        while ( !que.empty() ) {
            int cur_node = que.top().second;
            que.pop();
            for ( const auto& p : adjacent[cur_node] ) {
                int next_node = p.first, weight = p.second;
                // add cur_node as mid node to calc distance to next_node
                if ( distance[cur_node] + weight < distance[next_node] ) {
                    distance[next_node] = distance[cur_node] + weight;
                    que.emplace(distance[next_node], next_node);
                }
            }
        }
        int max_dist = *max_element(distance.begin() + 1, distance.end());
        return max_dist == INT_MAX ? -1 : max_dist;
    }
};




int main() {
    Solution s;
    vector<vector<int>> times = { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 }  };
    cout << s.networkDelayTime(times, 4, 2) << endl;
}
