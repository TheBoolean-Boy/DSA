class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int sum =0 ;
        for(int i = 0; i< n; i++){
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            if(sum > maxSum){
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};