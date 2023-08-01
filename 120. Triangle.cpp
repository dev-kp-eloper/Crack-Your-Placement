//Link - https://leetcode.com/problems/triangle/description/

class Solution {
public:
    // int f(int i, int j, vector<vector<int>> arr, vector<vector<int>>& dp, int n){
    //     if(i == n-1) return arr[n-1][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = arr[i][j] + f(i+1, j, arr, dp, n);
    //     int diag = arr[i][j] + f(i+1, j+1, arr, dp, n);

    //     return dp[i][j] = min(down, diag);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> below(n, 0);
        for(int i=0; i<n; i++){
            below[i] = triangle[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            vector<int> curr(i+1,0);
            for(int j=i; j>=0; j--){

                int down = triangle[i][j] + below[j];
                int diag = triangle[i][j] + below[j+1];

                curr[j] = min(down , diag);
            }
            below = curr;
        }
        return below[0];
    }
};
