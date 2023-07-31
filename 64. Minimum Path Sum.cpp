//Link - https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    // int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i == 0 and j == 0) return grid[i][j];
    //     if(i < 0 or j < 0) return 999;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = grid[i][j] + f(i-1, j, grid, dp);
    //     int left = grid[i][j] + f(i, j-1, grid, dp);

    //     return dp[i][j] = min(left, up);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, 0));

    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(i == 0 and j == 0) dp[i][j] = grid[i][j];
    //             else{
    //                 int up = grid[i][j];
    //                 if(i > 0) up += dp[i-1][j];
    //                 else up += 999;
    //                 int left = grid[i][j];
    //                 if(j > 0) left += dp[i][j-1];
    //                 else left += 999; 
    //                 dp[i][j] = min(left, up);
    //             }
    //         }
    //     }   
    //     return dp[m-1][n-1];
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 and j == 0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 999;
                    int left = grid[i][j];
                    if(j > 0) left += curr[j-1];
                    else left += 999; 
                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }   
        return prev[n-1];
    }
};
