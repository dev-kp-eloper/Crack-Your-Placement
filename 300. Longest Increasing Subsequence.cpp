//Link - https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    // int f(int idx, int pre_idx, vector<int>& nums, vector<vector<int>> &dp){
    //     if(idx == nums.size()) return 0;

    //     if(dp[idx][pre_idx+1] != -1) return dp[idx][pre_idx+1];

    //     int len;
    //     len = 0 + f(idx+1, pre_idx, nums, dp);
    //     if(pre_idx == -1 or nums[idx] > nums[pre_idx]){
    //         len = max(len, 1 + f(idx+1, idx, nums, dp));
    //     }

    //     return dp[idx][pre_idx+1] = len;
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //     //no base case as dp is already filled with 0

    //     for(int idx=n-1; idx>=0; idx--){
    //         for(int pre_idx=idx-1; pre_idx>=-1; pre_idx--){
    //             int len = 0 + dp[idx+1][pre_idx+1];
    //             if(pre_idx == -1 or nums[idx] > nums[pre_idx]){
    //                 len = max(len, 1 + dp[idx+1][idx+1]);
    //             }
    //             dp[idx][pre_idx+1] = len;
    //         }
    //     }

    //     return dp[0][-1+1];
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> next(n+1, 0);
    //     vector<int> curr(n+1, 0);
    //     //no base case as dp is already filled with 0

    //     for(int idx=n-1; idx>=0; idx--){
    //         for(int pre_idx=idx-1; pre_idx>=-1; pre_idx--){
    //             int len = 0 + next[pre_idx+1];
    //             if(pre_idx == -1 or nums[idx] > nums[pre_idx]){
    //                 len = max(len, 1 + next[idx+1]);
    //             }
    //             curr[pre_idx+1] = len;
    //         }
    //         next = curr;
    //     }

    //     return next[-1+1];
    // }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
        maxi = max(maxi,dp[i]);
        }

        return maxi;
        
    }
};
