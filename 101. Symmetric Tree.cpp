//Link - https://leetcode.com/problems/symmetric-tree/description/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return symmetric(root -> left, root -> right);
    }

    bool symmetric(TreeNode* left, TreeNode* right){
        if(left == NULL or right == NULL){
            return left == right;
        }

        if(left -> val != right -> val){
            return false;
        }

        return symmetric(left -> left, right -> right) and symmetric(left -> right, right -> left);
    }
};
