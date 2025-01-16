class Solution {
public:
   bool isboolcheck(string s, int start, int end){
        int n = s.size();
        // int start = 0, end = n-1;
        while(start < end){
            if(s[start] != s[end])return false;
            start++;
            end--;
        }
        return true;
   }
   bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;

        while(i < n){
            if(s[i] != s[j]){
                 return (isboolcheck(s, i+1, j) || isboolcheck(s, i, j-1));
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};