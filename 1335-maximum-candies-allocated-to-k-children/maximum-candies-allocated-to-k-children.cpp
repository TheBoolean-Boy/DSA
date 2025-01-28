class Solution {
public:
    int findMax(vector<int>&candies){
        int maxi = INT_MIN;
        for(int i = 0; i < candies.size(); i++){
            maxi = max(maxi, candies[i]);
        }
        return maxi;
    }

    bool compute(vector<int>&candies, int mid, long long k){
        long long totalKids = 0;
        for(int i = 0; i < candies.size(); i++){
            totalKids += candies[i]/mid;
            if(totalKids >=k)return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = findMax(candies);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            bool kidsallocated = compute(candies, mid, k);
            if(kidsallocated == true){
                low  = mid +  1;
                ans = mid;
            }
            else{
                high  = mid - 1;
            }
        }
        return ans;
    }
};