//Link - https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    // int f(int idx, int T, vector<int>& coins, vector<vector<int>>& dp){
    //     if(idx == 0){
    //         if(T % coins[0] == 0) return T / coins[0];
    //         else return 1e9;
    //     }

    //     if(dp[idx][T] != -1) dp[idx][T];

    //     int nottake = 0 + f(idx - 1, T, coins, dp);
    //     int take = 1e9;
    //     if(coins[idx] <= T) take = 1 + f(idx, T - coins[idx], coins, dp);

    //     return dp[idx][T] = min(take, nottake);
    // }

    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    //     for(int T=0; T<=amount; T++){
    //         if(T % coins[0] == 0) dp[0][T] = T / coins[0];
    //         else dp[0][T] = 1e9;
    //     }

    //     for(int idx=1; idx<n; idx++){
    //         for(int T=1; T<=amount; T++){
    //             int nottake = 0 + dp[idx - 1][T];
    //             int take = 1e9;
    //             if(coins[idx] <= T) take = 1 + dp[idx][T - coins[idx]];
    //             dp[idx][T] = min(take, nottake);
    //         }
    //     }

    //     int ans = dp[n-1][amount];
    //     if(ans >= 1e9)
    //         return -1;
    //     return ans;
    // }

    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0) prev[T] = T / coins[0];
            else prev[T] = 1e9;
        }

        for(int idx=1; idx<n; idx++){
            for(int T=1; T<=amount; T++){
                int nottake = 0 + prev[T];
                int take = 1e9;
                if(coins[idx] <= T) take = 1 + curr[T - coins[idx]];
                curr[T] = min(take, nottake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};
