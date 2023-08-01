//Link - https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int minans = INT_MAX;
        vector<int> prev(m, 0);
        for(int j=0; j<m; j++){
            prev[j] = grid[0][j];
        }

        for(int i=1; i<m; i++){
            vector<int> curr(m, 0);
            for(int last=0; last<m; last++){
                curr[last] = INT_MAX;
                for(int task=0; task<m; task++){
                    if(task != last){
                        curr[last] = min(curr[last], grid[i][last] + prev[task]);
                    }
                }
            }
            prev = curr;
        }

        for(int j=0; j<m; j++){
            minans = min(minans, prev[j]);
        }
        
        return minans;
    }

};
