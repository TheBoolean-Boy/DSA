class Solution {
public:
    bool checker(vector<int>&nums, int largestSum, int k){
        int cnt = 1; 
        int subArrSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(subArrSum + nums[i] <= largestSum){
                subArrSum += nums[i];
            }
            else{
                subArrSum = nums[i];
                cnt++;
                if(cnt > k)return false;
            }
        }
        return true;
    }
    int findSum(vector<int>&nums){
        int sum = 0;
        for(int i = 0;i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }
    int splitArray(vector<int>& nums, int k) {
        int low =  *max_element(nums.begin(), nums.end());
        int high =  findSum(nums);
        while(low <= high){
            int mid  = low  + (high - low)/2;
            if(checker(nums, mid,k)){
                high = mid - 1;
            }
            else{
                low = mid +  1;
            }
        }
        return low;
    }
};