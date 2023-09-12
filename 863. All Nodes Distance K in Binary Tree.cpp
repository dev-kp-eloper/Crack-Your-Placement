//Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp -> left){
                parent_track[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right){
                parent_track[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        markparent(root, parent_track, target);      

        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_lev = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_lev++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> left and !visited[temp -> left]){
                    q.push(temp -> left);
                    visited[temp -> left]  = true;
                }
                if(temp -> right and !visited[temp -> right]){
                    q.push(temp -> right);
                    visited[temp -> right] = true;
                }
                if(parent_track[temp] and !visited[parent_track[temp]]){
                    q.push(parent_track[temp]);
                    visited[parent_track[temp]]  = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};
