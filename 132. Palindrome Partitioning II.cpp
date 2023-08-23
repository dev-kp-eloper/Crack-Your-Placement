//Link - https://leetcode.com/problems/palindrome-partitioning-ii/description/

class Solution {
public:
    int isPalindrome(string& str){
        int l = str.size();
        int i=0, j=l-1;
        while(i < j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // int f(int i, int n, string& s, vector<int>& dp){
    //     if(i == n) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     string temp = "";

    //     int minCost = INT_MAX;
    //     for(int j=i; j<=n-1; j++){
    //         temp += s[j];
    //         if(isPalindrome(temp)){
    //             int cost = 1 + f(j+1, n, s, dp);
    //             minCost = min(minCost, cost);
    //         }
    //     }
    //     return dp[i] = minCost;
    // }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1 , 0);
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--){
            string temp = "";
            int minCost = INT_MAX;
            for(int j=i; j<=n-1; j++){
                temp += s[j];
                if(isPalindrome(temp)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;//for last partition it does partition out of string so we subtract 1 
    }
};
