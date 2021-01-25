#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;


// Solution 1 : Dijkstra SSP
class Solution {
private:
    typedef pair<double, int> PDI;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<PDI>> graph(n, vector<PDI>());
        for ( int i = 0; i < edges.size(); ++i ) {
            int from = edges[i][0], to = edges[i][1];
            double prob = succProb[i];
            graph[from].emplace_back(prob, to);
            graph[to].emplace_back(prob, from);
        }
        priority_queue<PDI, vector<PDI>, less<PDI>> que;
        vector<double> probs(n, 0);
        probs[start] = 1.0;
        que.emplace(0, start);
        while ( !que.empty() ) {
            int    cur_node = que.top().second;
            que.pop();
            for ( const auto& p : graph[cur_node]  ) {
                int next_node = p.second;
                if ( probs[cur_node] * p.first > probs[next_node] ) {
                    probs[next_node] = probs[cur_node] * p.first;
                    que.emplace(probs[next_node], next_node);
                }
            }
        }
        return probs[end];
    }
};

// Solution 2: Floyd 
// ET
class Solution2 { 
private:
    typedef pair<double, int> PDI;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<double>> probs(n, vector<double>(n, 0));
        for ( int i = 0; i < n; ++i ) {
            probs[i][i] = 1.0;
        }
        for ( int i = 0; i < edges.size(); ++i ) {
            int from = edges[i][0], to = edges[i][1];
            double prob = succProb[i];
            probs[from][to] = prob;
            probs[to][from] = prob;
        }
        for ( int k = 0; k < n; ++k ) {
            for ( int i = 0; i < n; ++i ) {
                for ( int j = 0; j < n; ++j ) {
                    probs[i][j] = max(probs[i][j], probs[i][k] * probs[k][j]);
                }
            }
        }
        return probs[start][end];
    }
};

int main() {
    Solution2 s;
    vector<vector<int>> edges = { {193, 229}, {133, 212}, {224, 465} };
    vector<double> succProb = { 0.91, 0.78, 0.64 };
    cout << s.maxProbability(500, edges, succProb, 193, 229) << endl;
}

