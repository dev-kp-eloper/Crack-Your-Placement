//Link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

class Solution {
public:
    // Method 1
    // TreeNode* prev = NULL;

    // void flatten(TreeNode* root) {
    //     if(root == NULL)return;

    //     flatten(root -> right);
    //     flatten(root -> left);

    //     root -> right = prev;
    //     root -> left = NULL;
    //     prev = root;
    // }

    // Method 2
    // void flatten(TreeNode* root) {
    //     if (root == nullptr) {
    //         return; 
    //     }
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* curr = st.top();
    //         st.pop();
    //         if(curr -> right != NULL) st.push(curr -> right);
    //         if(curr -> left != NULL) st.push(curr -> left);
    //         if(!st.empty())curr -> right = st.top();
    //         curr -> left = NULL;
    //     }
    // }

    // Method 3
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return; 
        }
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left){
                TreeNode* prev = curr -> left;
                while(prev -> right != NULL){
                    prev = prev -> right;
                }
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};
