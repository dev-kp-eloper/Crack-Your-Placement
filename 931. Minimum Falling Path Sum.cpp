//Link - https://leetcode.com/problems/minimum-falling-path-sum/description/?orderBy=most_votes

class Solution {
public:
    //Memoization
    // int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
    //     if(j < 0 or j >= matrix.size()) return 999;
    //     if(i == 0) return matrix[0][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
    //     int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);
    //     int d = matrix[i][j] + f(i-1,j,matrix,dp);

    //     return dp[i][j] = min(d, min(ld, rd));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int minans = INT_MAX;
    //     vector<vector<int>> dp(m, vector<int>(m, -1));
    //     for(int i=0; i<m; i++){
    //         int sol = f(m-1,i,matrix,dp);
    //         minans = min(minans, sol);
    //     }
    //     return minans;
    // }

    // Tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int minans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<m; i++){
            for(int j=0; j<m; j++){
            int ld = 1e9, rd = 1e9;
            if(j > 0) ld = matrix[i][j] + dp[i-1][j-1];
            if(j < m-1) rd = matrix[i][j] + dp[i-1][j+1];
            int d = matrix[i][j] + dp[i-1][j];
            dp[i][j] = min(d , min(ld,rd));
            }
        }

        for(int j=0; j<m; j++){
            minans = min(minans, dp[m-1][j]);
        }
        
        return minans;
    }
    
    //Space Optimization
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int minans = INT_MAX;
    //     vector<int> prev(m, 0);
    //     for(int j=0; j<m; j++){
    //         prev[j] = matrix[0][j];
    //     }

    //     for(int i=1; i<m; i++){
    //         vector<int> curr(m, 0);
    //         for(int j=0; j<m; j++){
    //         int ld = 1e9, rd = 1e9;
    //         int up=matrix[i][j] + prev[j];
    //             if(j-1>=0)
    //                 ld=matrix[i][j] + prev[j-1];
    //             if(j+1<m)
    //                 rd=matrix[i][j] + prev[j+1];
    //         curr[j] = min(up , min(ld,rd));
    //         }
    //         prev = curr;
    //     }

    //     for(int j=0; j<m; j++){
    //         minans = min(minans, prev[j]);
    //     }
        
    //     return minans;
    // }

};
