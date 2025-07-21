class Solution {
public:
    string makeFancyString(string s) {
        string p = "";
        int n = s.size();
        int c = 1;

        p.push_back(s[0]);

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                c++;
            } else {
                c = 1; 
            }

            if (c < 3) {
                p.push_back(s[i]);
            }
        }

        return p;
    }
};