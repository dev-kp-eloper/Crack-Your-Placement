//Link - https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left == NULL){
                pre.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right and prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == NULL){
                    prev -> right = curr;
                    pre.push_back(curr -> val);
                    curr = curr -> left;
                }
                else{
                    prev -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return pre;
    }
};
