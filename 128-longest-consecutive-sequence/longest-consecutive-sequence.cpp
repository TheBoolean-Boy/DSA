class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_set<int>st;
        for(int i =0; i< n; i++){
            st.insert(nums[i]);
        }    
        
        int longest = 0;
        for(auto it :st ){
            if(st.find(it-1) == st.end()){
                int x = it;
                count = 1;
                while(st.find(x+1) != st.end()){
                    x = x +1;
                    count+=1;
                }
                
            }
            longest = max(longest, count);
           
        }
        return longest;
    }
};