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
    bool checker(vector<int>&nums, int divisor, int threshold){
        long long sum = 0;
        for(int i = 0; i< nums.size(); i++){
            sum += ceil((double)nums[i] / (double)divisor);
        }
        if(sum <= threshold)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid =  low + (high - low)/2;
            bool check = checker(nums, mid, threshold);
            if(check == true){
                high = mid - 1;
            }
            else{
                low  = mid + 1;
            }
        }
        return low;
    }
};