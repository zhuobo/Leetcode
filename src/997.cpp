#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indegree(N, 0), outdegree(N, 0);
        for ( const auto& p : trust ) {
            ++indegree[p[1] - 1];
            ++outdegree[p[0] - 1];
        }
        for ( int i = 0; i < N; ++i ) {
            if ( indegree[i] == N - 1 && outdegree[i] == 0 ) {
                return i + 1;
            }
        }
        return -1;
    }
};

