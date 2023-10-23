class Solution {
public:
    bool isPowerOfFour(long n) {
        if(n == 1) return true;

        if(n <= 0) return false;

        while(n > 1) {
            if((n & 1) || (n & 2)) return false;

            n = n >> 2;
        }

        return true;
    }
};