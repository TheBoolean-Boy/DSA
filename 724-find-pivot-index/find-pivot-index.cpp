class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int presum = 0;
        for(int i = 0; i<n; i++){
            int rem = sum - nums[i]- presum;
            if(rem == presum){
                return i;
            }
            presum+= nums[i];
        }
        return -1;
    }
};