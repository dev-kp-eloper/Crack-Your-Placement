//Link - https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    // int f(int i, int j, string word1, string word2, vector<vector<int>>& dp){
    //     if(i < 0) return j+1;
    //     if(j < 0) return i+1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(word1[i] == word2[j]){
    //         return dp[i][j] =  0 + f(i-1, j-1, word1, word2, dp); //did no operation
    //     }
    //     else // did one of the three operation
    //         return dp[i][j] = min(1 + f(i, j-1, word1, word2, dp), min(1 + f(i-1, j, word1, word2, dp), 1 + f(i-1, j-1, word1, word2, dp)));
    // }

    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();

    //     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //     for(int i=0; i<n+1; i++) dp[i][0] = i; //because it a 1 based indexing now so i instead of i-1
    //     for(int j=1; j<m+1; j++) dp[0][j] = j; //same

    //     for(int i=1; i<n+1; i++){
    //         for(int j=1; j<m+1; j++){
    //             if(word1[i-1] == word2[j-1]){
    //                 dp[i][j] =  0 + dp[i-1][j-1]; //did no operation
    //             }
    //             else // did one of the three operation
    //                 dp[i][j] = min((1 + dp[i][j-1]), min((1 + dp[i-1][j]), (1 + dp[i-1][j-1])));
    //         }
    //     }

    //     return dp[n][m];
    // }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int j=0; j<m+1; j++) prev[j] = j; 

        for(int i=1; i<n+1; i++){
            curr[0] = i;
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] =  0 + prev[j-1]; //did no operation
                }
                else // did one of the three operation
                    curr[j] = min((1 + curr[j-1]), min((1 + prev[j]), (1 + prev[j-1])));
            }
            prev = curr;
        }

        return prev[m];
    }
};
