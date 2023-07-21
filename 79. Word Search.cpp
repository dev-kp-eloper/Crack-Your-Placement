//Link - https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool dfs(int r, int c, int i, vector<vector<char>>& board, string word){
        int m = board.size();
        int n = board[0].size();
        int len = word.size();
        if(i == len){
            return true;
        }
        if(r<0 or c<0 or r>=m or c>=n or word[i] != board[r][c]){
           return false;
        }
        char p = board[r][c];
        board[r][c] = '#';
        bool res = (dfs(r+1,c,i+1,board,word) or dfs(r,c+1,i+1,board,word)
         or dfs(r-1,c,i+1,board,word) or dfs(r,c-1,i+1,board,word));
        board[r][c] = p;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dfs(i,j,0,board,word)) return true;
            }
        }
        
        return false;
    }
};
