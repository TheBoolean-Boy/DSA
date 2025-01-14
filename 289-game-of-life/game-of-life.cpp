class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int  j = 0; j < m; j++){
                int alive = 0;
                if(i > 0 && abs(board[i-1][j]) == 1)alive++;
                if(i < n-1 && abs(board[i+1][j]) == 1)alive++;
                if(j > 0 && abs(board[i][j-1]) == 1)alive++;
                if(j < m-1 && abs(board[i][j+1]) == 1) alive++;
                if(i > 0 && j < m-1 && abs(board[i-1][j+1]) == 1)alive++;
                if(i > 0 && j > 0 && abs(board[i-1][j-1]) == 1)alive++;
                if(i < n-1 && j < m-1 && abs(board[i+1][j+1]) == 1)alive++;
                if(j > 0 && i < n-1 && abs(board[i+1][j-1]) == 1)alive++;


                if(board[i][j] == 1){
                    if(alive > 3 || alive < 2){
                    board[i][j] = -1;
                }
                }
                if(board[i][j] == 0){
                    if(alive == 3){
                        board[i][j] = 2;
                    }
                }
            }
        }
         for(int i = 0; i < n; i++){
            for(int  j = 0; j < m; j++){
                if(board[i][j] == 2)board[i][j] = 1;
                else if(board[i][j] == -1)board[i][j] = 0;
            }
        }
    }
};