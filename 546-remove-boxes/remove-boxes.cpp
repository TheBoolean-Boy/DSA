class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if (n == 0) return 0;
        
        // dp[i][j][k] = maximum points for boxes[i...j] with k boxes of color boxes[i] before this range
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        
        return helper(boxes, 0, n - 1, 0, dp);
    }
    
private:
    int helper(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (i > j) return 0;
        
        if (dp[i][j][k] != 0) return dp[i][j][k];
        
        // Find all consecutive boxes with same color as boxes[i]
        int originalI = i, originalK = k;
        while (i + 1 <= j && boxes[i + 1] == boxes[i]) {
            i++;
            k++;
        }
        
        // Option 1: Remove boxes[originalI...i] directly
        int res = (k + 1) * (k + 1) + helper(boxes, i + 1, j, 0, dp);
        
        // Option 2: Try to merge with boxes of same color later
        for (int m = i + 1; m <= j; m++) {
            if (boxes[m] == boxes[originalI]) {
                res = max(res, helper(boxes, i + 1, m - 1, 0, dp) + 
                              helper(boxes, m, j, k + 1, dp));
            }
        }
        
        return dp[originalI][j][originalK] = res;
    }
};