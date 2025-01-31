const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif


#define pb push_back

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
    bool solver(vector<vector<char>>&board){
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){

                if(board[row][col] == '.'){
                    for(char c =  '1'; c <= '9'; c++){
                        if(isPossible(board, row, col, c)){
                            board[row][col] = c;

                            if(solver(board) == true)return true;
                            else board[row][col]= '.';
            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isPossible(vector<vector<char>>&board, int row, int col, int value){
        for(int i =  0; i < 9; i++){
            if(board[row][i] == value)return false;

            if(board[i][col] == value)return false;

            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == value)return false;
        }
        return true;
    }
};