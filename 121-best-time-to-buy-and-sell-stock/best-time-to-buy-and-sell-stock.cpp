class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxProfit = 0;
        int minCost = prices[0];
        int n = prices.size();


        for(int i =0 ; i < n; i++){
            int cost = prices[i] - minCost;
            maxProfit = max(maxProfit, cost);
            minCost = min(minCost, prices[i]);
        }
        return maxProfit;
    }
};