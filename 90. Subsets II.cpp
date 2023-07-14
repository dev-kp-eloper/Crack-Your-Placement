//Link - https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    void findsubset(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int idx){
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx and nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findsubset(nums,ans,ds,i+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findsubset(nums,ans,ds,0);
        return ans;
    }
};
