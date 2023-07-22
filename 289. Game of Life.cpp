//Link - https://leetcode.com/problems/game-of-life/description/

class Solution {
public:
    int check(int row, int col, vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for(int i=row-1; i<row+2; i++){
            for(int j=col-1; j<col+2; j++){
                if((i == row and j == col) or i<0 or i==m or j<0 or j==n) continue;

                if(board[i][j] == 1 or board[i][j] == 3) cnt++;
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp(board.begin(), board.end());
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                int count = check(row,col,board);
                if(board[row][col] == 1){
                    if(count == 2 or count == 3) board[row][col] = 3;
                }
                else{
                    if(count == 3) board[row][col] = 2;
                }
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if(board[i][j] == 1) board[i][j] = 0;
                else if(board[i][j] == 2 or board[i][j] == 3) board[i][j] = 1;
    }
};
