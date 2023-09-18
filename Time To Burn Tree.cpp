//Link - https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?leftPanelTab=0

#include<bits/stdc++.h>

int FindMaxDistance(BinaryTreeNode<int>* target, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mp)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    map<BinaryTreeNode<int>*, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while(!q.empty()){
        int size = q.size();
        int flag = 0;
        for(int i=0; i<size; i++){
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            if(temp -> left and !vis[temp -> left]){
                flag = 1;//this is to show that we did burn someone so we can increment maxi 
                vis[temp -> left] = 1;
                q.push(temp -> left);
            }
            if(temp -> right and !vis[temp -> right]){
                flag = 1;//this is to show that we did burn someone so we can increment maxi 
                vis[temp -> right] = 1;
                q.push(temp -> right);
            }
            if(mp[temp] and !vis[mp[temp]]){
                flag = 1;//this is to show that we did burn someone so we can increment maxi 
                vis[mp[temp]] = 1;
                q.push(mp[temp]);
            }
        }
        if(flag == 1)maxi++;
    }
    return maxi;
}

BinaryTreeNode<int>* parentchecker(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mp, int start)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* res;
    while(!q.empty()){
        BinaryTreeNode<int>* temp = q.front();
        if(temp -> data == start)res = temp;
        q.pop();
        if(temp -> left){
            mp[temp -> left] = temp;
            q.push(temp -> left);
        }
        if(temp -> right){
            mp[temp -> right] = temp;
            q.push(temp -> right);
        }
    }
    return res;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mp;
    BinaryTreeNode<int>* target = parentchecker(root, mp, start);
    int ans = FindMaxDistance(target, mp);
    return ans;
}
