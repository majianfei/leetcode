#include <iostream>

/**
 * Runtime: 24 ms, faster than 89.48% of C++ online submissions for Kth Smallest Element in a BST.
 * Memory Usage: 21.6 MB, less than 35.83% of C++ online submissions for Kth Smallest Element in a BST.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(--k==0)return p->val;
            st.pop();
            p = p->right;
        }
        return 0;
    }
};