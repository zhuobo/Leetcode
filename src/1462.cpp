#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> rgraph(n, vector<int>());
        vector<int> indegree(n, 0);
        // reverse every path in the graph
        for ( const auto& prerequisite : prerequisites ) {
            int from = prerequisite[0], to = prerequisite[1];
            rgraph[to].push_back(from);
            ++indegree[from];
        }
        queue<int> que;
        // next_nodes[i]中存储所有i能够到达的节点，也就是i作为前导的节点
        vector<unordered_set<int>> next_nodes(n, unordered_set<int>());
        // 入度为0，没有前导节点，先入队
        for ( int i = 0; i < n; ++i ) {
            if ( indegree[i] == 0 ) {
                que.push(i);
            }
        }
        while ( !que.empty() ) {
            int cur_node = que.front();
            que.pop();
            // cur_node直接指向的节点to
            // to节点不仅仅是cur_node的前导
            // to同时也是那些以cur_node为前导的前导
            for ( int to : rgraph[cur_node] ) {
                next_nodes[to].insert(cur_node);
                for ( int node : next_nodes[cur_node] ) {
                    next_nodes[to].insert(node);
                }
                // 拓扑排序，入度为0可以访问
                if ( --indegree[to] == 0 ) {
                    que.push(to);
                }
            }
        }
        vector<bool> flag;
        for ( const auto& query : queries ) {
            int from = query[0], to = query[1];
            if ( next_nodes[from].find(to) != next_nodes[from].end() ) {
                flag.push_back(true);
            } else {
                flag.push_back(false);
            }
        }
        return flag;
    }
};

// ## 方法2：动态规划

// 利用前导关系的传递性，事实上里Floyd算法，要判断i，j之间的连通性，通过不断引入第三点k，判断是否可以联通。

class Solution2 {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for ( const auto& prerequisite : prerequisites ) {
            int from = prerequisite[0], to = prerequisite[1];
            dp[from][to] = true;
        } 
        for ( int k = 0; k < n; ++k ) {
            for ( int i = 0; i < n; ++i ) {
                for ( int j = 0; j < n; ++j ) {
                    if ( dp[i][k] && dp[k][j] ) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        vector<bool> flag;
        for ( const auto& query : queries ) {
            int from = query[0], to = query[1];
            if ( dp[from][to] ) {
                flag.push_back(true);
            } else {
                flag.push_back(false);
            }
        }
        return flag;
    }
};
