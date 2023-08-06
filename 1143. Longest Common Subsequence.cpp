//Link - https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    // int f(int idx1, int idx2, string text1, string text2, vector<vector<int>>& dp){
    //     if(idx1 == 0 or idx2 == 0) return 0;

    //     if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    //     if(text1[idx1-1] == text2[idx2-1])
    //         return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, text1, text2, dp);

    //     return dp[idx1][idx2] = max(f(idx1 - 1, idx2, text1, text2, dp), f(idx1, idx2 - 1, text1, text2, dp));
    // }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);

        for(int idx1=1; idx1<=n1; idx1++){
            for(int idx2=1; idx2<=n2; idx2++){
                if(text1[idx1-1] == text2[idx2-1])
                    curr[idx2] = 1 + prev[idx2 - 1];

                else curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
            }
            prev = curr;
        }

        return prev[n2];
    }
};
