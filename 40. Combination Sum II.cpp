//Link - https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    void subsum(vector<int>& nums, int target, int idx, vector<vector<int>>& ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            if(i>idx and nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            ds.push_back(nums[i]);
            subsum(nums,target - nums[i],i+1,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        subsum(candidates,target,0,ans,ds);
        return ans;
    }
};
