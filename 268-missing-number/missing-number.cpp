class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i <=n; i++){
            sum += i;
        }
        int missingSum = 0;
        for(int i = 0; i< n; i++){
            missingSum += nums[i];
        }
        return (sum - missingSum);
    }
};