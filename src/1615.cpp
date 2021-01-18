#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution 1: brute force just beat 5.22%
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        for ( const auto& road : roads ) {
            ++indegree[road[0]];
            ++indegree[road[1]];
        }
        vector<int> count;
        for ( int i = 0; i < n - 1; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                int total = indegree[i] + indegree[j];
                for ( const auto& road : roads ) {
                    if ( i == road[0] && j == road[1] ||
                         j == road[0] && i == road[1] ) {
                        --total;
                    }
                }
                count.push_back(total);
            }
        }
        return *max_element(count.begin(), count.end());
    }
};


class Solution2 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

    }
};
