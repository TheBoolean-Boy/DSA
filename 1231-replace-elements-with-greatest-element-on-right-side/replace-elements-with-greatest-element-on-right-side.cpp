class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = arr[n-1];
        vector<int>ans(n, -1);
        if(arr.size() == 1)return {-1};
        
        for(int i = n-2; i >= 0; i--){
            // int temp = arr[i];
            ans[i] = maxRight;
            if(arr[i] > maxRight){
                maxRight  = arr[i];
            }
        }
        return ans;
    }
};