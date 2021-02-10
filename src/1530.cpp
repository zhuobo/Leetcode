#include <vector>
#include "structure.h"

using std::vector;

class Solution {
private:
    int distance;
    int res;
    // 返回当前子树到所有叶子节点的距离
    vector<int> dfs(TreeNode* root) {
        if ( root == nullptr ) return vector<int>();
        if ( root->left == nullptr && root->right == nullptr ) {
            return {0};
        }
        vector<int> ret;
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);

        for ( int i : l ) {
            for ( int j : r ) {
                if ( i + j + 2 <= distance ) ++res;
            }
        }

        for ( int i : l ) {
            ret.push_back(i + 1);
        }
        for ( int i : r ) {
            ret.push_back(i + 1);
        }
        return ret;
    }
public:
    int countPairs(TreeNode* root, int _distance) {
        distance = _distance;
        res = 0;
        dfs(root);
        return res;
    }
};
