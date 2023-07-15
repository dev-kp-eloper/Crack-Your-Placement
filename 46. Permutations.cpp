//Link - https://leetcode.com/problems/permutations/

class Solution {
public:
    void findpermute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int freq[]){
        int n = nums.size();
        int d = ds.size();
        if(d == n){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<n; i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                findpermute(nums,ds,ans,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        int freq[n];
        for(int i=0; i<n; i++) freq[i] = 0;
        findpermute(nums, ds, ans, freq);
        return ans;
    }
};
