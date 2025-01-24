class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 1)return 0;
        int n = height.size();
        int start = 0, end = n-1;
        int maxArea = INT_MIN;
        while(start < end){
            int Area = min(height[start], height[end])* (end - start);
            maxArea = max(maxArea, Area);
            if(height[start] < height[end])start++;
            else end--;
        }
        return maxArea;
    }
};