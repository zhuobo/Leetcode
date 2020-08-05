#ifndef __0337_H__
#define __0337_H__
#include <utility>
#include <algorithm>
#include "structure.h"

class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return std::max(res.first, res.second);
    }
    // std::pair.first:表示选择跟节点的最大和
    // std::pair.second:表示不选择跟节点的最大和
    std::pair<int, int> dfs(TreeNode *root) {
        if ( !root ) return std::make_pair(0, 0);
        std::pair<int, int> left = dfs(root->left);
        std::pair<int, int> right = dfs(root->right);
        // 选择跟节点,那么两个子节点就不可选
        int selected = root->val + left.second + right.second;
        // 如果不选择根节点,那么左右子树的跟节点可选可不选
        int notSelect = max(left.first, left.second) + max(right.first, right.second);
        return std::make_pair(selected, notSelect);
    }
};
#endif
