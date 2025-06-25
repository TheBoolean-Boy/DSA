class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) return false;

        int k = x;
        int rev =0;
        while( k > 0){
            int r = k %10;
            if( (rev >INT_MAX/10) || (rev < INT_MIN/10))return false;
            rev = rev * 10 + r;
            k = k/10;
        }
        if(rev == x )return true;
        else return false;
    }
};