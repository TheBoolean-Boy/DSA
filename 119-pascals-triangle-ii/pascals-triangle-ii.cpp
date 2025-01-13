class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long res = 1;
        vector<int>ans;
        ans.push_back(1);
        int rowNumber  = rowIndex + 1;
        for(int i = 1; i < rowNumber; i++){
            res  = res * (rowNumber - i);
            res = res/i;
            ans.push_back(res);
        }
        return ans;
    }
};