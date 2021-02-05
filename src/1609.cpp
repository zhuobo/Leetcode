#include "structure.h"
#include <queue>
#include <vector>

using namespace std;

// solution1: using a vector to store nums layer by layer
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if ( root == nullptr ) return true;
        queue<TreeNode*> que;
        que.push(root);
        bool flag = true;
        bool level_even = true;
        while ( !que.empty() ) {
            int size = que.size();
            vector<int> nums;
            while ( size-- ) {
                TreeNode* node = que.front();
                que.pop();
                nums.push_back(node->val);
                if ( node->left ) que.push(node->left);
                if ( node->right ) que.push(node->right);
            }
            if ( level_even && (!odd(nums) || !increase(nums)) ) {
                flag = false;
                break;
            }
            if ( !level_even && (!even(nums) || !decrease(nums)) ) {
                flag = false;
                break;
            }
            level_even = !level_even;
        }
        return flag;
    }
    bool even(vector<int>& nums) {
        for ( int num : nums ) {
            if ( num % 2 == 1 ) return false;
        }
        return true;
    }

    bool odd(vector<int>& nums) {
        for ( int num : nums ) {
            if ( num % 2 == 0 ) return false;
        }
        return true;
    }

    bool increase(vector<int>& nums) {
        int len = nums.size();
        if ( len == 1 ) return true;
        for ( int i = 1; i < len; ++i ) {
            if ( nums[i] <= nums[i - 1] ) return false;
        }
        return true;        
    }

    bool decrease(vector<int>& nums) {
        int len = nums.size();
        if ( len == 1 ) return true;
        for ( int i = 1; i < len; ++i ) {
            if ( nums[i] >= nums[i - 1] ) return false;
        }
        return true;
    }
};


// solution2: solution1 is so stupid!
class Solution2 {
public:
    bool isEvenOddTree(TreeNode* root) {
        if ( root == nullptr ) return false;
        queue<TreeNode*> que;
        bool level_even = true, ret = true;
        que.push(root);
        int prev;
        while ( !que.empty() ) {
            int size = que.size();
            if ( level_even ) {
                prev = INT_MIN;
            } else {
                prev = INT_MAX;
            }
            while ( size-- ) {
                TreeNode* node = que.front();
                que.pop();
                if ( level_even ) {
                    if ( node->val <= prev ) {
                        ret = false; break;
                    } else if ( node->val % 2 == 0 ) {
                        ret = false; break;
                    } else {
                        prev = node->val;
                    }
                } else {
                    if ( node->val >= prev ) {
                        ret = false; break;
                    } else if ( node->val % 2 == 1 ) {
                        ret = false; break;
                    } else {
                        prev = node->val;
                    }
                }
                if ( node->left != nullptr ) {
                    que.push(node->left);
                }
                if ( node->right != nullptr ) {
                    que.push(node->right);
                }
            }
            level_even = !level_even;
        }
        return ret;
    }
};
