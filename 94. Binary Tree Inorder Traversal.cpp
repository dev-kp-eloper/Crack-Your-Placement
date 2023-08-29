//Link - https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        TreeNode* f = root;
        stack<TreeNode*> st;
        while(true){
            if(f != NULL){
                st.push(f);
                f = f -> left;
            }
            else{
                if(st.empty()) break;
                f = st.top();
                st.pop();
                in.push_back(f->val);
                f = f -> right;
            }
        }
        return in;
    }
};
