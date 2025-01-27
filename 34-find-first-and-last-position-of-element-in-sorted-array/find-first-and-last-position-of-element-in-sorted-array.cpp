class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        vector<int>ans;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                int first = mid, last = mid;
                while(first > 0 && nums[first-1] == target)first--;
                ans.push_back(first);
                while(last < n-1 && nums[last+1] == target)last++;
                ans.push_back(last);
                return ans;
            }
            else if(nums[mid] > target){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};