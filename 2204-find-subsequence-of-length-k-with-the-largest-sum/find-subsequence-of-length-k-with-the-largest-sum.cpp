class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for (int i = 0; i < nums.size(); i++) {
            if (minHeap.size() < k) {
                minHeap.push({nums[i], i});
            } else if (nums[i] > minHeap.top().first) {
                minHeap.pop();
                minHeap.push({nums[i], i});
            }
        }
        
        vector<pair<int, int>> selected;
        while (!minHeap.empty()) {
            selected.push_back(minHeap.top());
            minHeap.pop();
        }
        
        sort(selected.begin(), selected.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        
        vector<int> result;
        for (const auto& p : selected) {
            result.push_back(p.first);
        }
        
        return result;
    }
};