/**
 * Definition for a binary tree node.
 */
#include <stdio.h>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * 递归解法
*/

/**
 * Runtime: 4 ms, faster than 94.38% of C++ online submissions for Invert Binary Tree.
 * Memory Usage: 9.3 MB, less than 22.67% of C++ online submissions for Invert Binary Tree.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        invertTree(root->right);
        invertTree(root->left);
        std::swap(root->left,root->right);
        return root;
    }
};

/**
 * 非递归解法
 */

/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
 * Memory Usage: 9.2 MB, less than 32.45% of C++ online submissions for Invert Binary Tree.
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL)return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left != NULL)q.push(node->left);
            if (node->right != NULL)q.push(node->right);
            
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return root;
    }
};