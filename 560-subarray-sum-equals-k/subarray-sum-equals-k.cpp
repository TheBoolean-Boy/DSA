class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        mp[sum] = 1;

        for(int i= 0; i < n; i++){
            sum += nums[i];
            int rem = sum - k;
            count += mp[rem];
            mp[sum]++;
        }
        return count;
    }
};