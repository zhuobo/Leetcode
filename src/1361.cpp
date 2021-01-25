#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0), outdegree(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for ( int i = 0; i < n; ++i ) {
            if ( leftChild[i] != -1 ) {
                ++indegree[leftChild[i]];
                ++outdegree[i];
                graph[i].push_back(leftChild[i]);
            }
            if ( rightChild[i] != -1 ) {
                ++indegree[rightChild[i]];
                ++outdegree[i];
                graph[i].push_back(rightChild[i]);
            }
        }
        // 1. only one vertex has indegree 0
        // 2. max outdegree is 2
        // 3. max indegree is 1
        // 4. no loop in the graph
        int indgree0 = count(indegree.begin(), indegree.end(), 0);
        int max_outdegree = *max_element(outdegree.begin(), outdegree.end());
        int max_indegree = *max_element(indegree.begin(), indegree.end());
        if ( indgree0 != 1 || max_outdegree > 2 || max_indegree > 1 ) {
            return false;
        }

        // top sort to find if there is a loop in the graph
        queue<int> que;
        for ( int i = 0; i < n; ++i ) {
            if ( indegree[i] == 0 ) {
                que.push(i);
                --n;
            }
        }    
        while ( !que.empty() ) {
            int cur_node = que.front();
            que.pop();
            for ( int next_node : graph[cur_node] ) {
                if ( --indegree[next_node] == 0 ) {
                    que.push(next_node);
                    --n;
                }
            }
        }
        return n == 0;
    }
};
