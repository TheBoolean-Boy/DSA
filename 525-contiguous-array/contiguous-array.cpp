class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)nums[i] = -1;
        }
        unordered_map<int, int>mp;
        int maxLen = 0;
        int sum = 0;
        for(int i  =  0; i< n; i++){
            sum += nums[i];
            if(sum == 0){
                maxLen = max(maxLen, i+1);
            }
            int rem =sum - 0;
            if(mp.count(rem)){
                int len = i -  mp[rem];
                maxLen = max(maxLen, len);
            }
            if(!mp.count(sum)){
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};