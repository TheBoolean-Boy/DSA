class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        int n = word.length();
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && word[j] == word[i]) {
                j++;
            }
            res += (j - i - 1);
            i = j;
        }
        return res;
    }
};