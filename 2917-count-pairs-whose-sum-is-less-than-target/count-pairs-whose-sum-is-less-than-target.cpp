class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int  n = nums.size();
        int left = 0, right = n - 1;
        int count = 0;
    
        while(left < right){
            int pairSum = nums[left] + nums[right];
            if(pairSum < target){
                count += right - left;
                left++;
            }
            else{
                right--;
            }
        }

        return count;
    }
};