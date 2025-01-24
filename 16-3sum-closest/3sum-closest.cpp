class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX/10;
        for(int i = 0; i<n-2; i++){
            if( i > 0 && nums[i] == nums[i-1] )continue;
            
            int j = i+1;
            int k = n-1;
            while(j <  k){
                int sum = nums[i]+ nums[j] + nums[k];
                
                if(abs(sum - target) < abs(closest - target)){
                    closest = sum;
                }
                if(sum > target)k--;
                else j++;
            }
        }
        return closest;
    }
};