//Link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

class BSTIterator {
    
    stack<TreeNode*> st;
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp -> right);
        else pushAll(temp -> left);
        return temp -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

private:
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse){
                node = node -> right;
            }
            else node = node -> left;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator left(root, false);//next
        BSTIterator right(root, true);//berfore

        int i = left.next();
        int j = right.next();

        while(i<j){
            if(i + j == k)return true;
            else if(i + j < k) i = left.next();
            else j = right.next();
        }

        return false;
    }
};
