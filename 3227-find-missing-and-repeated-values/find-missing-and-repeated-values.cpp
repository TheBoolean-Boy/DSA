class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n*n;
        long long sn = N* (N+1)/2;
        long long s2n = N * (N+1) * (2*N + 1)/6;

        long long sum = 0, sum2sq = 0;

        for(int i = 0; i <n; i++){
            for (int j = 0; j < n; j++){
                sum += grid[i][j];
                sum2sq += grid[i][j] * grid[i][j];
            }
        }

        long long val1 = sum - sn;
        long long val2 = sum2sq - s2n;

        val2 = val2/val1;

        long long a = (val1+val2)/2;
        long long b = val2 - a;

        return {(int)a, (int)b};
    }
};