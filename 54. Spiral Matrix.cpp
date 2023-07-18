//Link - https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int currdir = 0;
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int currR = 0, currC = 0;
        while(ans.size() < m*n){
            ans.push_back(matrix[currR][currC]);
            matrix[currR][currC] = -1000;
            int nextR = currR + dir[currdir][0];
            int nextC = currC + dir[currdir][1];

            if(nextR < 0 or nextR >= m or nextC < 0 or nextC >= n or matrix[nextR][nextC] == -1000){
                currdir = (currdir+1)%4; //this will change the directions
            }

            currR += dir[currdir][0];
            currC += dir[currdir][1];
        }
        return ans;
    }
};
