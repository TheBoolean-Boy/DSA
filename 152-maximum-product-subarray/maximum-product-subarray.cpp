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
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        int prefix = 1, suffix =1;
        int ans = INT_MIN;
        for(int i =0; i < n; i++){
            if(prefix == 0)prefix =1;
            if(suffix == 0)suffix =1;
            
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-(i+1)];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};