class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), i = 0;
        string ans ="";

        while(i < n){
            string temp = "";
            while(i < n && s[i] == ' '){
                i++;
            }
            while(i < n  && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(!temp.empty()){
                if(ans.empty())ans = temp;
                else{
                    ans = temp + " " + ans;
                }
            }
        }
        return ans;

        return ans;
    }
};