//Link - https://leetcode.com/problems/binary-tree-preorder-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(root == NULL) return pre;
        
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* f = st.top();
            st.pop();
            pre.push_back(f->val);
            if(f->right) st.push(f->right);
            if(f->left) st.push(f->left);
        }
        return pre;
    }
};
