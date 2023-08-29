//Link - https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        if(root == NULL) return post;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            TreeNode* f = root;
            f = st1.top();
            st1.pop();
            st2.push(f);
            if(f->left) st1.push(f->left);
            if(f->right) st1.push(f->right);
        }

        while(!st2.empty()){
            TreeNode* temp = st2.top();
            post.push_back(temp->val);
            st2.pop();
        }
        return post;
    }
};
