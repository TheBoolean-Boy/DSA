class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int, int>mp;
        for(auto it: nums1){
            mp[it] = 1;
        }
        for(auto it: nums2){
            if(mp[it]){
                ans.push_back(it);
                mp[it] = 0;
            }
        }
        return ans;
    }
};