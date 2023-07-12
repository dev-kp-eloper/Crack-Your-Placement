//Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int temp1,temp2;
        for(int i=0; i<n; i++){
            temp1 = abs(nums[i]);
            temp2 = nums[temp1 - 1];
            if(temp2 < 0){
                ans.push_back(temp1);
            }
            temp2 = -temp2;
        }
        return ans;
    }
};
