class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        sort(str.begin(), str.end());

        string first = str[0];
        string last = str[n-1];

        string ans ="";

        for(int i = 0; i < first.size(); i++){
            if(first[i] != last[i]){
                break;
            }
            ans += first[i];
        }

        return ans;
    }
};