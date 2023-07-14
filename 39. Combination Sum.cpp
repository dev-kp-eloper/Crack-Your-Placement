//Link - https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void subsum(vector<int>& nums, int target, int idx, vector<vector<int>>& ans, vector<int>& ds){
        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            subsum(nums,target - nums[idx],idx,ans,ds);
            ds.pop_back();
        }
        subsum(nums,target,idx+1,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        subsum(candidates,target,0,ans,ds);
        return ans;
    }
};
