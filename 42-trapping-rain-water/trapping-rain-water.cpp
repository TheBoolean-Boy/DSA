class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0], rmax = height[n-1];
        int i = 0, j = n-1;
        int totalvolume = 0;
        while(i < j){
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);
            if(height[i] > height[j]){
                totalvolume += rmax - height[j];
                j--;
            }
            else{
                totalvolume += lmax - height[i];
                i++;
            }
        }
        return totalvolume;
    }
};