//Link - https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

int findCeil(Node* root, int input) {
    int ceil = -1;
    while(root){
        if(input == root -> data){
            ceil = root -> data;
            return ceil;
        }
        if(input > root -> data){
            root = root -> right;
        }
        else{
            ceil = root -> data;
            root = root -> left;
        }
    }
    return ceil;
}
