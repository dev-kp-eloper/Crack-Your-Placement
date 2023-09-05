//Link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            int l = p.second;
            if(mp.find(l) == mp.end()) mp[l] = temp -> data;
            if(temp -> left){
                q.push({temp -> left, l-1});
            }
            if(temp -> right){
                q.push({temp -> right, l+1});
            }
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};
