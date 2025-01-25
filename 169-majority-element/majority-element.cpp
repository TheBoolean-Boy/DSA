class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int count =0;
        int n = nums.size();
        for(int i = 0; i< n;i++){
            if(count == 0){
                el = nums[i];
                count++;
            }
            else if(nums[i] == el){
                count++;
            }
            else{
                count--;
            }
        } 
        count = 0;
        for(int i = 0 ; i < n; i++){
            if(nums[i] == el)count++;
        }
        if(count > (n/2))return el;
        return el;
    }
};