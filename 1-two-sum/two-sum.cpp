class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int, int>>copy(n);

        for(int i = 0; i < n; i++){
            copy[i] = { nums[i], i };
        }

        sort(copy.begin(), copy.end());
        int i = 0, j = n-1;
        while(i < j){
            int sum = copy[i].first + copy[j].first;
            if(sum < target)i++;
            else if( sum > target)j--;
            else{
                break;
            }
        }

        return {copy[i].second, copy[j].second};

    }
};