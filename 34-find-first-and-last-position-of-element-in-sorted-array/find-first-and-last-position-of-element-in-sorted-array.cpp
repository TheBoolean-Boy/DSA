class Solution {
public:
    int lastO(vector<int>&nums, int n, int target){
       int low = 0, high  =  n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int firstO(vector<int>&nums, int n, int target){
         int low = 0, high  =  n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
       
        int first = firstO(nums, n, target);
        if(first == -1) return {-1, -1};
        int last = lastO(nums, n, target);
        return {first, last};
    }
};