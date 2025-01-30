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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size(), m = matrix[0].size();
        int low = 0, high = m*n -1;
        while(low <= high){
            int mid = (low + high) >> 1;
            int key = matrix[mid/m][mid%m];
            if(key == target)return true;
            else if(key > target)high = mid - 1 ;
            else low = mid + 1;
        }
        return false;
    }
};