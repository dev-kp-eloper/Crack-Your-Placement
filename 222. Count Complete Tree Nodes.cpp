//Link - https://leetcode.com/problems/count-complete-tree-nodes/description/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findleftH(root);
        int rh = findrightH(root);

        if(lh == rh)return (1 << lh) - 1;

        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    int findleftH(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root -> left;
        }
        return height;
    }

    int findrightH(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root -> right;
        }
        return height;
    }
};
