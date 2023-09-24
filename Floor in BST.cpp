//Link - https://practice.geeksforgeeks.org/problems/floor-in-bst/1

class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int ceil = -1;
        while(root){
            if(x == root -> data){
                ceil = root -> data;
                return ceil;
            }
            if(x < root -> data){
                root = root -> left;
            }
            else{
                ceil = root -> data;
                root = root -> right;
            }
        }
        return ceil;
    }
};
