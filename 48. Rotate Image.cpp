//Link - https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int k=0;
        // for(int i=m-1, k=0; i>=m/2; i--,k++){
        //     for(int j=0; j<n; j++){
        //         swap(matrix[i][j], matrix[k][j]);
        //     }
        // }
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<m; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
