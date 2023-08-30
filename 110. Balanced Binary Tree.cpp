//Link - https://leetcode.com/problems/balanced-binary-tree/description/

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
    bool isBalanced(TreeNode* root) {
        return balanced(root) != -1;
    }

    int balanced(TreeNode* root){
        if(root == NULL) return 0;

        int lt = balanced(root -> left);
        if(lt == -1) return -1;
        int rt = balanced(root -> right);
        if(rt == -1) return -1;

        if(abs(lt - rt) > 1) return -1;

        return max(lt , rt) + 1;
    }
};
