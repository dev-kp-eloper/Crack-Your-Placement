//Link - https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?leftPanelTab=0

bool isLeaf(TreeNode<int> *root) {
  return !root -> left && !root -> right;
}

void addleft(TreeNode<int> *root, vector<int>& res){
    TreeNode<int> * curr = root -> left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr -> data);
        if(curr -> left) curr = curr -> left;
        else curr = curr -> right;
    }
}

void addleaves(TreeNode<int> *root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root -> data);
        return;
    }
    if(root -> left) addleaves(root -> left, res);
    if(root -> right) addleaves(root -> right, res);
}

void addright(TreeNode<int> *root, vector<int>& res){
    TreeNode<int> * curr = root -> right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr -> data);
        if(curr -> right) curr = curr -> right;
        else curr = curr -> left;
    }
    for (int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if(root == NULL)return res;
    if(!isLeaf(root)) res.push_back(root -> data);
    addleft(root,res);
    addleaves(root,res);
    addright(root,res);
    return res;
}
