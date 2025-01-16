class Solution {
public:
    bool Firstpalindrome(string s){
        int n  = s.size();
        int start = 0, end = n-1;
        while(start < end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it: words){
            bool checker = Firstpalindrome(it);
            if(checker  == true)return it;
        }
        return "";
    }
};