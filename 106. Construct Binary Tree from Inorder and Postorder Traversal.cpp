//Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmap;

        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]] = i;
        }

        TreeNode* root = Build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inmap);

        return root;
    }


    TreeNode* Build(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder,
        int inStart, int inEnd, map<int, int>& inmap){
        
        if(postStart > postEnd or inStart > inEnd)return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inroot = inmap[root -> val];
        int numleft = inroot - inStart;

        root -> left = Build(postorder, postStart, postStart + numleft - 1,
        inorder, inStart, inroot - 1, inmap);

        root -> right = Build(postorder, postStart + numleft, postEnd - 1,
        inorder, inroot + 1, inEnd, inmap);

        return root;
    }
};
