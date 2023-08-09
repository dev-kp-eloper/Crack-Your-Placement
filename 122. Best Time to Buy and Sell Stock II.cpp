//Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    // int f(int idx, int buy, vector<int>& prices, vector<vector<int>> &dp){
    //     if(idx == prices.size()) return 0;

    //     if(dp[idx][buy] != -1) return dp[idx][buy];

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[idx] + f(idx+1, 0, prices, dp), 0 + f(idx+1, 1, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[idx] + f(idx+1, 1, prices, dp), 0 + f(idx+1, 0, prices, dp));
    //     }
    //     return dp[idx][buy] = profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int buy = 1;

    //     vector<vector<int>> dp(n+1, vector<int>(2, 0));

    //     dp[n][0] = dp[n][1] = 0;

    //     for(int idx=n-1; idx>=0; idx--){
    //         for(int buy=0; buy<=1; buy++){
    //             int profit = 0;
    //             if(buy){
    //                 profit = max(-prices[idx] + dp[idx+1][0], 0 + dp[idx+1][1]);
    //             }
    //             else{
    //                 profit = max(prices[idx] + dp[idx+1][1], 0 + dp[idx+1][0]);
    //             }
    //             dp[idx][buy] = profit;
    //         }
    //     }

    //     return dp[0][1];
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;

        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        ahead[0] = ahead[1] = 0;

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[idx] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
};
