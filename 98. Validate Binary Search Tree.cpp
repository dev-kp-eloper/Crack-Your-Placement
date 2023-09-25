//Link - https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
    bool isBST(TreeNode* root, long long minV, long long maxV){
        if(root == NULL){
            return true;
        }

        if(root -> val >= maxV or root -> val <= minV){
            return false;
        }

        return isBST(root -> left, minV, root ->  val) and isBST(root -> right, root -> val, maxV);
    }
    
    bool isValidBST(TreeNode* root) {
        long long int min = -1e12, max = 1e12;
        bool ans = isBST(root, min, max);

        return ans;
    }
};
