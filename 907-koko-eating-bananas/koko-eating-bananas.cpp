class Solution {
public:
    int findMax(vector<int>&piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long computeHours(vector<int>&piles, int mid){
        long long ans = 0;
        for(int i= 0; i< piles.size(); i++){
            ans += ceil((double)piles[i]/(double)mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1, high =findMax(piles);
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalHours = computeHours(piles, mid);
            if(totalHours <= h){
                ans =  mid;
                high = mid - 1;
            }
            else{
                low = mid  + 1;
            }
        }
        return low;
    }
};