class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0; int right = n-1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if( sum > target ){
                right--;
            }
            else if( sum < target){
                left++;
            }
            else{
                vector<int>ans = { left+1, right+1};
                return ans;
            }
        }
        return {0,0};
    }
};