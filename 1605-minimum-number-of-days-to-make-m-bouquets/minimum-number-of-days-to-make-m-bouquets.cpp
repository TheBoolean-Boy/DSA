class Solution {
public:
    bool possible(vector<int>&bloomDay,int day,  int m, int k){
        int bouqets = 0, cnt = 0;
        for(int i = 0 ; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                bouqets += (cnt/k);
                cnt = 0;
            }
        }
        bouqets += (cnt/k);
        if(bouqets >= m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < ((long long)m *(long long)k))return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            bool checker = possible(bloomDay, mid, m, k);
            if(checker == true){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};