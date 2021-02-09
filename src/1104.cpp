#include "structure.h"
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;
        int level = 1, node_count = 1;
        while ( node_count * 2 <= label ) {
            node_count *= 2;
            ++level;
        }
        while ( level != 0 ) {
            path.push_back(label);
            int max_num = int(pow(2, level) - 1);
            int min_num = int(pow(2, level - 1));
            label = int((min_num + max_num - label) / 2);
            --level;
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
};
