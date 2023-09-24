//link - https://www.codingninjas.com/studio/problems/minimum-element-in-bst_8160462?leftPanelTab=0

int minVal(Node* root){
	// Write your code here.	
	if(root == NULL)return -1;

	while(root -> left)root = root -> left;

	return root -> data;
}
