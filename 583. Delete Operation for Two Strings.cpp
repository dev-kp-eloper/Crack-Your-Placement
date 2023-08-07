//Link - https://leetcode.com/problems/delete-operation-for-two-strings/description/

class Solution {
public:
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

    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        int n1 = word1.size();
        int n2 = word2.size();

        int a = n1 - lcs;
        int b = n2 - lcs;
        return a + b;
    }
};
