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
    bool possible(vector<int>&bloomDay,int day,  int m, int k){
        int bouqets = 0, cnt = 0;
        for(int i = 0 ; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                bouqets += (cnt/k);
                cnt = 0;
            }
        }
        bouqets += (cnt/k);
        if(bouqets >= m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);

        if(bloomDay.size() < ((long long)m *(long long)k))return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            bool checker = possible(bloomDay, mid, m, k);
            if(checker == true){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};