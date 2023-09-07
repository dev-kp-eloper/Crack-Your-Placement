//Link - https://www.codingninjas.com/studio/problems/all-root-to-leaf-paths-in-binary-tree._983599?leftPanelTab=0

void support(BinaryTreeNode<int> * root, vector<string>& ans, string ds){
    if(root == NULL)return ;

    if(root -> left == NULL and root -> right == NULL){
        ds += to_string(root -> data);
        ans.push_back(ds);
        return;
    }

    ds += to_string(root -> data) + " ";
    support(root -> left, ans, ds);
    support(root -> right, ans, ds);
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string> ans;
    support(root, ans, "");
    return ans;
}
