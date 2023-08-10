//Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    // int f(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
    //     if(cap == 0) return 0;
    //     if(idx == prices.size()) return 0;

    //     if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[idx] + f(idx+1, 0, cap, prices, dp), 0 + f(idx+1, 1, cap, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[idx] + f(idx+1, 1, cap-1, prices, dp), 0 + f(idx+1, 0, cap, prices, dp));
    //     }
    //     return dp[idx][buy][cap] = profit;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + after[0][cap], 0 + after[1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + after[1][cap-1], 0 + after[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }

        return after[1][2];
    }
};
