class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int cnt = 0;
        int sum = 0;
        mp[sum] = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int rem = sum - k ;
            cnt += mp[rem];
            mp[sum]++;
        }
        return cnt;
    }
};