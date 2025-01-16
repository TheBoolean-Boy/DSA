class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n  = nums.size();
        for (int i = 0; i < n; i++){
            if(nums[i] == 0)nums[i] = -1;
        }

        unordered_map<int, int>mp;
        int sum = 0;
        int maxLen =0;
        for(int i =0; i< n; i++){
            sum += nums[i];
            if(sum == 0){
                maxLen = max(maxLen, i+1);
            }
            int rem = sum - 0;
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                maxLen = max(maxLen, len);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};