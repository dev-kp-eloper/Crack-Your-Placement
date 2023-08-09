//Link - https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
public:
    int prime = 1e9+7;

    // int f(int i, int j, string s, string t, vector<vector<int>>& dp){
    //     if(j < 0) return 1;
    //     if(i < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == t[j]){
    //         return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp); 
    //     }
    //     else return dp[i][j] = f(i-1, j, s, t, dp);
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));

    //     for(int i=0; i<n+1; i++) dp[i][0] = 1;
    //     for(int j=1; j<m+1; j++) dp[0][j] = 0;

    //     for(int i=1; i<n+1; i++){
    //         for(int j=1; j<m+1; j++){
    //             if(s[i-1] == t[j-1]){
    //                 dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime; 
    //             }
    //             else dp[i][j] = dp[i-1][j];
    //         }
    //     }

    //     return dp[n][m];
    // }

    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<int> prev(m+1, 0);
    //     vector<int> curr(m+1, 0);

    //     prev[0] = curr[0] = 1;

    //     for(int i=1; i<n+1; i++){
    //         for(int j=1; j<m+1; j++){
    //             if(s[i-1] == t[j-1]){
    //                 curr[j] = (prev[j-1] + prev[j])%prime; 
    //             }
    //             else curr[j] = prev[j];
    //         }
    //         prev = curr;
    //     }

    //     return prev[m];
    // }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1, 0);

        prev[0] = 1;

        for(int i=1; i<n+1; i++){
            for(int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = (prev[j-1] + prev[j])%prime; 
                }
                else prev[j] = prev[j];
            }
        }

        return prev[m];
    }
};
