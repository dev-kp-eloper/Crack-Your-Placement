//Link - https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

class Solution {
public:
    void findsubset(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& ds){
        int n = nums.size();
        if(ds.size() == 2){
            ans.push_back(ds);
        }
        for(int i=idx; i<n; i++){
            ds.push_back(nums[i]);
            findsubset(nums,i+1,ans,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        findsubset(nums,0,ans,ds);
        return ans;
    }
};
