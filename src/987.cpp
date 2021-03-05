#include <map>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include "structure.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;  // (col, (depth, val))
        queue<pair<TreeNode*, int>> que; // (treenode, col)
        vector<vector<int>> res;
        if ( root == nullptr ) {
            return res;
        }
        que.emplace(root, 0);
        int count;
        TreeNode *cur_node;
        int depth = 0, col = 0;

        while ( !que.empty() ) {
            count = que.size();
            while ( count-- ) {
               cur_node = que.front().first;
               col      = que.front().second;
               que.pop();
               if ( m.find(col) == m.end() ) {
                   m[col] = vector<pair<int, int>>();
               }
               m[col].emplace_back(depth, cur_node->val);
               if ( cur_node->left != nullptr ) {
                   que.emplace(cur_node->left, col - 1);
               }
               if ( cur_node->right != nullptr ) {
                   que.emplace(cur_node->right, col + 1);
               }
            }
            ++depth;
        }
        res.resize(m.size());
        int index = 0;
        for ( auto& [col, vec] : m ) {
            sort(vec.begin(), vec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
                    if ( p1.first == p2.first ) return p1.second < p2.second;
                    return p1.first < p2.first;
                    });
            for ( const auto& [depth, val] : vec ) {
                res[index].push_back(val);
            }
            ++index;
        }
        return res;
    }

};
