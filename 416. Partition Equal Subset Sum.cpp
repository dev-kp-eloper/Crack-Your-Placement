//Link - https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1, 0);
        vector<bool> curr(k+1, 0);


        prev[0] = curr[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;

        for(int i=1; i<n; i++){
            for(int target=1; target<=k; target++){
                bool nottake = prev[target];
                bool take = false;
                if(target >= arr[i])
                    take = prev[target-arr[i]];
                curr[target] = take or nottake;
            }
            prev = curr;
        }
        
        return prev[k];
    }


    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i=0; i<n; i++) totalsum += nums[i];
        if(totalsum%2 != 0) return false;
        int target = totalsum/2;
        return subsetSumToK(n, target, nums);
    }
};
