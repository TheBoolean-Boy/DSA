class Solution {
public:
    bool checker(vector<int>&weights, int capacity, int days){
        int cnt = 1;
        long long sum = 0;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] <= capacity){
                sum += weights[i];
            }
            else{
                cnt++;
                sum = weights[i];
            }
        }
        if(cnt <= days)return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i = 0; i < weights.size(); i++){
            high += weights[i];
        }
        while(low <= high){
            int mid = low + (high - low)/2;
            bool check = checker(weights,mid, days);
            if(check == true){
                high  = mid  - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};