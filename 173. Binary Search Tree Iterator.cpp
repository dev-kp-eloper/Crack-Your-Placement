//Link - https://leetcode.com/problems/binary-search-tree-iterator/description/

class BSTIterator {
private: stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp -> right);
        return temp -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            node = node -> left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
