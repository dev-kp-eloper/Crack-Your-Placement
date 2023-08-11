//Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
public:
    // int f(int idx, int transNo, vector<int>& prices, int k, vector<vector<int>>& dp){
    //     if(idx == prices.size() or transNo == 2*k) return 0;

    //     if(dp[idx][transNo] != -1) return dp[idx][transNo];

    //     int profit = 0;
    //     if(transNo % 2 == 0){
    //         profit = max(-prices[idx] + f(idx+1, transNo+1, prices, k, dp), 0 + f(idx+1, transNo, prices, k, dp));
    //     }
    //     else{
    //         profit = max(prices[idx] + f(idx+1, transNo+1, prices, k, dp), 0 + f(idx+1, transNo, prices, k, dp));
    //     }
    //     return dp[idx][transNo] = profit;
    // }

    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    //     for(int i=0; i<=2*k; i++) dp[n][i] = 0;// no need to write these two base cases as dp is already filled with 0
    //     for(int i=0; i<=n; i++) dp[i][2*k] = 0;

    //     for(int idx=n-1; idx>=0; idx--){
    //         for(int transNo=2*k-1; transNo>=0; transNo--){
    //             int profit = 0;
    //             if(transNo % 2 == 0){
    //                 profit = max(-prices[idx] + dp[idx+1][transNo+1], 0 + dp[idx+1][transNo]);
    //             }
    //             else{
    //                 profit = max(prices[idx] + dp[idx+1][transNo+1], 0 + dp[idx+1][transNo]);
    //             }
    //             dp[idx][transNo] = profit;
    //         }
    //     }

    //     return dp[0][0];
    // }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0);
        vector<int> curr(2*k+1, 0);

        for(int idx=n-1; idx>=0; idx--){
            for(int transNo=2*k-1; transNo>=0; transNo--){
                int profit = 0;
                if(transNo % 2 == 0){
                    profit = max(-prices[idx] + after[transNo+1], 0 + after[transNo]);
                }
                else{
                    profit = max(prices[idx] + after[transNo+1], 0 + after[transNo]);
                }
                curr[transNo] = profit;
            }
            after = curr;
        }

        return after[0];
    }
};
