class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        long long sn  = n * (n+1)/2;
        long long s2n = ((long long)(n)*(long long)(n+1)*(long long)(2*n+1))/6;

        long long sum = 0;
        long long sum2sq = 0;

        for(int i = 0; i < n; i++){
            sum += (long long)nums[i];
            sum2sq += (long long)nums[i] * (long long)nums[i];
        }
        long long val1 = sum - sn;
        long long val2 = sum2sq - s2n;

        val2 = val2/val1;

        long long x = (val1 + val2)/2;
        long long y = val2 - x;

        return{(int)x, (int)y};
    }
};