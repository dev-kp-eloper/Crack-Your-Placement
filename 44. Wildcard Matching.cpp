//Link - https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    // int f(int i, int j, string s, string p, vector<vector<int>>& dp){
    //     if(i < 0 and j < 0) return true;
    //     if(i < 0 and j >= 0) return false;
    //     if(j < 0 and i >= 0){
    //         for(int k=0; k<=i; k++){
    //             if(p[k] != '*') return false;
    //         }
    //         return true;
    //     }

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(p[i] == s[j] or p[i] == '?'){
    //         return dp[i][j] = f(i-1, j-1, s, p, dp);
    //     }
    //     if(p[i] == '*'){
    //         return dp[i][j] = f(i-1, j, s, p, dp) | f(i, j-1, s, p, dp);
    //     }
    //     return dp[i][j] = false;
    // }

    // bool isMatch(string s, string p) {
    //     int n = p.size();
    //     int m = s.size();

    //     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    //     dp[0][0] = true;
    //     for(int j=1; j<m+1; j++) dp[0][j] = false;
    //     for(int i=1; i<n+1; i++){
    //         bool flag = true;
    //         for(int k=1; k<=i; k++){
    //             if(p[k-1] != '*'){
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         dp[i][0] = flag;
    //     }

    //     for(int i=1; i<n+1; i++){
    //         for(int j=1; j<m+1; j++){
    //             if(p[i-1] == s[j-1] or p[i-1] == '?'){
    //                 dp[i][j] = dp[i-1][j-1];
    //             }
    //             else if(p[i-1] == '*'){
    //                 dp[i][j] = dp[i][j-1] or dp[i-1][j];
    //             }
    //             else dp[i][j] = false;
    //         }
    //     }

    //     return dp[n][m];
    // }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        prev[0] = true;
        for(int j=1; j<m+1; j++) prev[j] = false;

        for(int i=1; i<n+1; i++){
            //assign curr every time
            bool flag = true;
            for(int k=1; k<=i; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for(int j=1; j<m+1; j++){
                if(p[i-1] == s[j-1] or p[i-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[i-1] == '*'){
                    curr[j] = curr[j-1] or prev[j];
                }
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};
