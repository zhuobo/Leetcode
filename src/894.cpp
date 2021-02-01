#include <vector>
#include "structure.h"

using std::vector;

class Solution {
public:
    // 返回值：节点数为N的所有符合题意得树得根节点
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        // 偶数返回空，没有可以生成的树
        if ( (N & 1) == 0 ) {
            return res;
        }
        // 单一节点的情况
        if ( N == 1 ) {
            res.push_back(new TreeNode(0));
            return res;
        }
        // N - 1拆为2个奇数
        for ( int left_count = 1; left_count <= N - 2; left_count += 2 ) {
            vector<TreeNode*> left_trees = allPossibleFBT(left_count);
            vector<TreeNode*> right_trees = allPossibleFBT(N - left_count - 1);
            // 组合即可
            for ( auto left_tree : left_trees ) {
                for ( auto right_tree : right_trees ) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left_tree;
                    root->right = right_tree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
