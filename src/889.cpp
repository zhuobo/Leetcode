#include <vector>
#include "structure.h"

using std::vector;
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return generate(pre, post, 0, 0, pre.size());
    }
    // first1:      first num in pre
    // first2:      first num in post
    // subtree_len: the number of nodes in cur sub tree
    // generate tree with pre[first1, first1 + subtree_len] and post[first2, first2 + subtree_len]
    TreeNode* generate(vector<int>& pre, vector<int>& post, int first1, int first2, int subtree_len) {
        if ( subtree_len == 0 ) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[first1]);
        if ( subtree_len == 1 ) {
            return root;
        }
        // find the length of sub tree left and right
        int l_len = distance(post.begin() + first2, find(post.begin() + first2, post.end(), pre[first1 + 1])) + 1;
        root->left = generate(pre, post, first1 + 1, first2, l_len);
        root->right = generate(pre, post, first1 + l_len + 1, first2 + l_len, subtree_len - l_len - 1);
        return root;
    }
};
