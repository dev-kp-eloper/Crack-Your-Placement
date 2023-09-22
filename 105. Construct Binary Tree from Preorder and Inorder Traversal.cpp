//Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;

        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]] = i;
        }

        TreeNode* root = Build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);

        return root;
    }

    TreeNode* Build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder,
        int inStart, int inEnd, map<int, int>& inmap){
        
        if(preStart > preEnd or inStart > inEnd)return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inroot = inmap[root -> val];
        int numleft = inroot - inStart;

        root -> left = Build(preorder, preStart + 1, preStart + numleft,
        inorder, inStart, inroot - 1, inmap);

        root -> right = Build(preorder, preStart + numleft + 1, preEnd,
        inorder, inroot + 1, inEnd, inmap);

        return root;
    }
};
