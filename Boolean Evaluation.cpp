//Link - https://www.codingninjas.com/studio/problems/boolean-evaluation_1214650?leftPanelTab=0

#include <bits/stdc++.h>

#define ll long long

int mod = 1000000007;

// int f(int i, int j, int isTrue, string & exp, vector<vector<vector<int>>> &dp){
//     if(i > j) return 0;
//     if(i == j){
//         if(isTrue) return exp[i] == 'T';
//         else return exp[i] == 'F';
//     }

//     if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue]; 

//     ll ways = 0;
//     for(int idx=i+1; idx<=j-1; idx+=2){
//         ll LT = f(i, idx-1, 1, exp, dp);
//         ll LF = f(i, idx-1, 0, exp, dp);
//         ll RT = f(idx+1, j, 1, exp, dp);
//         ll RF = f(idx+1, j, 0, exp, dp);

//         if(exp[idx] == '&'){
//             if(isTrue) ways = (ways + (LT * RT) % mod) % mod;
//             else ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
//         }
//         else if(exp[idx] == '|'){
//             if(isTrue) ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
//             else ways = (ways + (LF * RF) % mod) % mod;
//         }
//         else{
//             if(isTrue) ways = (ways + (LF * RT) % mod + (LT * RF) % mod) % mod;
//             else ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
//         }
//     }

//     return dp[i][j][isTrue] = ways;
// }

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=n-1; j++){
            if(i > j) continue;
            for(int isTrue=0; isTrue<=1; isTrue++){
                if(i == j){
                    if (isTrue == 1) dp[i][j][isTrue] = (exp[i] == 'T');
                    else dp[i][j][isTrue] = (exp[i] == 'F');
                    continue;
                }

                ll ways = 0;
                for(int idx=i+1; idx<=j-1; idx+=2){
                    ll LT = dp[i][idx-1][1];
                    ll LF = dp[i][idx-1][0];
                    ll RT = dp[idx+1][j][1];
                    ll RF = dp[idx+1][j][0];

                    if(exp[idx] == '&'){
                        if(isTrue) ways = (ways + (LT * RT) % mod) % mod;
                        else ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
                    }
                    else if(exp[idx] == '|'){
                        if(isTrue) ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
                        else ways = (ways + (LF * RF) % mod) % mod;
                    }
                    else{
                        if(isTrue) ways = (ways + (LF * RT) % mod + (LT * RF) % mod) % mod;
                        else ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
                    }
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n - 1][1];
}
