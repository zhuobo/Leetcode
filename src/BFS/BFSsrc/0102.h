#ifndef __0102_H__
#define __0102_H__
#include <vector>
#include <queue>
#include "structure.h"

/**
 * 题目描述:将一颗给定的树按照层次遍历,每一层组织成一个单链表
 * 解法:
 *      BFS ,使用广度优先搜索的方法遍历树,由于需要记录当前层有哪些节点,并且要将这些节点组织成单链表
 *      因此可以在从队列中弹出节点之前先记录当前队列的节点数量,然后就只弹出这些节点即可
 **/
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if ( !root ) return res;
        std::queue<TreeNode*> que;
        que.push(root);
        while ( !que.empty() ) {
            int n = que.size();
            std::vector<int> curLevel;
            for ( int i = 0; i < n; ++i ) {
                TreeNode *node = que.front();
                curLevel.push_back(node->val);
                if ( node->left ) que.push(node->left);
                if ( node->right ) que.push(node->right);
                que.pop();
            }
            res.emplace_back(curLevel);
        }
        return res;
    }
};

#endif
