class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int getMinIndex = min_element(nums.begin(), nums.end())- nums.begin();
        int getMaxIndex = max_element(nums.begin(), nums.end())- nums.begin();

        int leftdiff =  min(getMinIndex, getMaxIndex) +1;
        int rightdiff = nums.size() - max(getMinIndex, getMaxIndex);
        int middleDiff = abs(getMinIndex - getMaxIndex);

        return min({leftdiff+rightdiff, leftdiff+middleDiff, rightdiff+middleDiff});
    }
};