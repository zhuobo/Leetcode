#ifndef __0513_H__
#define __0513_H__
#include "structure.h"
#include <queue>
/**
 * 题目描述：给定一个二叉树，在树的最后一行找到最左边的值。
 * 解法：
 *      要找到最后一层的最左边一个节点，可以利用 BFS 。常规　BFS　是先访问左子树，后访问右子树，
 *      因此正常情况下最后访问的节点应该是最后一层的最右边节点（因为是最后一个被加入队列），因此
 *      可以反过来，先访问右子树，然后访问左子树，那么最后访问的节点就是最后一层的最做左边节点
 **/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> que;
        que.push(root);
        int res = root->val;
        while ( !que.empty() ) {
            TreeNode *node = que.front();
            res = node->val;
            if ( node->right ) que.push(node->right);
            if ( node->left ) que.push(node->left);
            que.pop();
        }
        return res;
   }
};

#endif
