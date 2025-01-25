class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m ; i++){
            for(int j = 0; j< n; j++){
                int alive = 0;
                if(j < n-1 && abs(board[i][j+1]) == 1)alive++;
                if(i < m-1 && abs(board[i+1][j]) == 1)alive++;
                if(i < m-1 && j < n-1 && abs(board[i+1][j+1]) == 1)alive++;
                if(i > 0 && j < n-1 && abs(board[i-1][j+1]) == 1)alive++;
                if(i > 0 && abs(board[i-1][j]) == 1 )alive++;
                if(i > 0 && j > 0 && abs(board[i-1][j-1]) == 1)alive++;
                if(j > 0 && abs(board[i][j-1]) == 1)alive++;
                if(i < m-1 && j > 0 && abs(board[i+1][j-1]) == 1)alive++;

                if(board[i][j] == 1){
                    if(alive < 2 || alive > 3){
                        board[i][j] = -1;
                    }
                }
                else if(board[i][j] == 0){
                    if(alive == 3){
                        board[i][j] = 2;
                    }
                }
            }
        }

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2)board[i][j] = 1;
                if(board[i][j] == -1)board[i][j] = 0;
            }
        }
    }
};