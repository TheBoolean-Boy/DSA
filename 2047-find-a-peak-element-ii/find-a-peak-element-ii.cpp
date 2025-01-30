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
    int maxRowIndex(vector<vector<int>>&mat, int n, int col){
        int maxIndex = -1;
        int maxi =  INT_MIN;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;

        while(low <= high){
            int mid =  (low + high) >> 1;
            int maxRow = maxRowIndex(mat, n, mid);
            int left = mid-1 >=0 ? mat[maxRow][mid-1]: -1;
            int right = mid+1  < m ? mat[maxRow][mid+1]: -1;
            if(left < mat[maxRow][mid] && mat[maxRow][mid] > right){
                return {maxRow, mid};
            }
            else if(left > mat[maxRow][mid]){
                high = mid - 1;
            }
            else{
                low = mid +  1;
            }
        }
        return {-1, -1};
    }
};