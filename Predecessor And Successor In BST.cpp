//Link - https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049?leftPanelTab=0

int predecessor(TreeNode *root, int key){
    int ans = -1;
    TreeNode* pre = NULL;
        while(root){
            if(key <= root -> data){
                root = root -> left;
            }
            else{
                pre = root;
                root = root -> right;
            }
        }
        if(pre != NULL)ans = pre -> data;
        return ans;
}

int Successor(TreeNode *root, int key){
    int ans = -1;
    TreeNode* succ = NULL;
    while(root){
        if(key >= root -> data){
            root = root -> right;
        }
        else{
            succ = root;
            root = root -> left;
        }
    }
    
    if(succ != NULL)ans = succ -> data;
    return ans;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int, int> p;
    p.first = predecessor(root, key);
    p.second = Successor(root, key);

    if(p.first)

    return p;
}
