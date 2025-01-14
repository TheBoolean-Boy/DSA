class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sz = grid.size();
        long long N = sz*sz;
        long long SN = (N *(N + 1))/2;
        long long S2N = (N * (N + 1) * (2*N +1))/6;

        long long S = 0, S2 =0;
        for(int i = 0; i < sz; i++){
            for(int j =0; j< sz; j++){
                S += grid[i][j];
                S2 += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }

        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 = val2/val1;

        long long x = (val1 + val2)/2;
        long long y = val2 - x;

        return{(int)x, (int)y};
    }
};