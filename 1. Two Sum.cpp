//Link - https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> mp;
        for(int i=0; i<nums.size(); i++){
            mp.insert({nums[i] , i});
            int value = target - nums[i];
            if(mp.count(value) && mp[value] != i){
                return {i, mp[value]};
            }
        }

        return {};
    }
};
