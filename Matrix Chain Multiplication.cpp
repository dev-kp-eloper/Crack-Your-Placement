//Link - https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_624880?leftPanelTab=0

#include <bits/stdc++.h>

// int f(int i, int j, int* arr, vector<vector<int>>& dp){
//     if(i == j)
//         return 0;

//     if(dp[i][j] != -1) return dp[i][j];
        
//     int mini = 1e9;
    
//     // partioning loop
//     for(int k = i; k<= j-1; k++){
        
//         int ans = f(i,k,arr, dp) + f(k+1,j,arr, dp) + arr[i-1]*arr[k]*arr[j];
        
//         mini = min(mini,ans);
        
//     }
    
//     return dp[i][j] = mini;
// }

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=n; i>=1; i--){
        for(int j=i+1; j<n+1; j++){
            int mini = 1e9;
            for(int k = i; k<= j-1; k++){
        
            int ans = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
            
            mini = min(mini,ans);
        
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n];
}
