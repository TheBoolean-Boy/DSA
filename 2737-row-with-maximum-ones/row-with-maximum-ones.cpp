class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat[0].size();
        int n = mat.size();
        int maxCount = 0;
        int maxRow = 0;
        for(int i = 0; i < n ; i++){
            int count =0;
            for(int j = 0 ; j < m; j++){
                count += mat[i][j];
            }
            if(count > maxCount){
                maxRow = i;
                maxCount = count;
            }
        }
        return {maxRow, maxCount};
    }
};