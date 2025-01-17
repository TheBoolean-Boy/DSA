class Solution {
public:
    int myAtoi(string s) {
          long res = 0, sign = 1;
        int i = 0;
        
        while(s[i] == ' ')i++;
        if(s[i] == '-'|| s[i] == '+'){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        
        while(s[i] >= '0' && s[i] <= '9'){
            res = res * 10 + (s[i] -'0');
            if(sign*res > INT_MAX)return INT_MAX;
            if(sign*res < INT_MIN)return INT_MIN;
            i++;
        }
        
        return (int)sign*res;
        
    }
};