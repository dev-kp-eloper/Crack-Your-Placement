//Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return Build(preorder, idx, INT_MAX);
    }

    TreeNode* Build(vector<int> arr, int& idx, int UB){
        if(idx == arr.size() or arr[idx] > UB)return NULL;

        TreeNode* root = new TreeNode(arr[idx++]);
        root -> left = Build(arr, idx, root -> val); 
        root -> right = Build(arr, idx, UB);

        return root; 
    }
};
