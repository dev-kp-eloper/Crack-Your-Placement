//Link - https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&campaign=striver_dp_videos

#include <bits/stdc++.h> 
// bool f(int idx, int k, vector<int> &arr, vector<vector<int>> &dp){
//     if(k == 0) return true;
//     if(idx == 0) return (arr[0] == k);

//     if(dp[idx][k] != -1) return dp[idx][k];

//     bool nottake = f(idx - 1, k, arr, dp);
//     bool take = false;
//     if(k >= arr[idx])
//         take = f(idx-1, k-arr[idx], arr, dp);

//     return dp[idx][k] = take or nottake;
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1, 0);
    vector<bool> curr(k+1, 0);


    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

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
