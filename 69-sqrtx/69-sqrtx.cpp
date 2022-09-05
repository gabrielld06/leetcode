class Solution {
public:
    long mySqrt(long a) {
        if(a == 0) return 0;
        
        double r = a, x = a+1;
	
        while(abs(r - x) >= 1e-10) {
            x = r;

            r = 0.5 *(x + a/x);
        }

        return r;
    }
};