//Link - https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

// int f(int idx, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp){
//     if(idx == 0){
//         return ((int)(W/weight[0])*profit[0]);
//     }

//     if(dp[idx][W] != -1) return dp[idx][W];

//     int nottake = 0 + f(idx - 1, W, profit, weight, dp);
//     int take = 0;
//     if(weight[idx] <= W) take = profit[idx] + f(idx, W - weight[idx], profit, weight, dp);

//     return dp[idx][W] = max(take, nottake);
// }

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     // Write Your Code Here.
//     vector<vector<int>> dp(n, vector<int>(w+1, 0));

//     for(int W=0; W<=w; W++) dp[0][W] = ((int)(W/weight[0])*profit[0]);

//     for(int idx=1; idx<n; idx++){
//         for(int W=0; W<=w; W++){
//             int nottake = 0 + dp[idx - 1][W];
//             int take = 0;
//             if(weight[idx] <= W) take = profit[idx] + dp[idx][W - weight[idx]];
//             dp[idx][W] = max(take, nottake);
//         }
//     }

//     return dp[n-1][w];
// }

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int> prev(w+1, 0);

    for(int W=0; W<=w; W++) prev[W] = ((int)(W/weight[0])*profit[0]);

    for(int idx=1; idx<n; idx++){
        for(int W=0; W<=w; W++){
            int nottake = 0 + prev[W];
            int take = 0;
            if(weight[idx] <= W) take = profit[idx] + prev[W - weight[idx]];
            prev[W] = max(take, nottake);
        }
    }

    return prev[w];
}
