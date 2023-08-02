//Link - https://leetcode.com/problems/cherry-pickup-ii/description/

class Solution {
public:
    //Memoization
    // int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     if(j1 < 0 or j1 >= n or j2 < 0 or j2 >= n) return -1e8;
    //     if(i == m-1){
    //         if(j1 == j2) return grid[i][j1];
    //         else return grid[i][j1] + grid[i][j2];
    //     }
    //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    //     int maxi = -1e8;
    //     for(int d1=-1; d1<=1; d1++){
    //         for(int d2=-1; d2<=1; d2++){
    //             int value = 0;
    //             if(j1 == j2){
    //                 value = grid[i][j1];
    //             }
    //             else{
    //                 value = grid[i][j1] + grid[i][j2];
    //             }
    //             value += f(i+1, j1+d1, j2+d2, grid, dp);
    //             maxi = max(maxi, value);
    //         }
    //     }
    //     return dp[i][j1][j2] = maxi;
    // }

    // int cherryPickup(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    //     return f(0, 0, n-1, grid, dp);
    // }


    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prev(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));

        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){
                    if(j1 == j2) prev[j1][j2] = grid[m-1][j1];
                    else prev[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }

        for(int i=m-2; i>=0; i--){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int maxi = -1e8;
                    for(int d1=-1; d1<=1; d1++){
                        for(int d2=-1; d2<=1; d2++){
                            int value = 0;
                            if(j1 == j2){
                                value = grid[i][j1];
                            }
                            else{
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+d1 >= 0 and j1+d1 < n and j2+d2 >= 0 and j2+d2 < n){
                                value += prev[j1+d1][j2+d2];
                            }
                            else value += -1e9;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }
        return prev[0][n-1];
    }
};
