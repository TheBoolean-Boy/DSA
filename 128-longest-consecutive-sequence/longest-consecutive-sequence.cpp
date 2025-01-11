class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        unordered_set<int>st;
        int n = nums.size();
        int count =  0;
        int longest =  1;

        for (int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int x = it;
                count  = 1;
                while(st.find(x+1) != st.end()){
                    count++;
                    x = x+1;
                }
            }
            longest =  max(count, longest);
        }
        return longest;

    }
};