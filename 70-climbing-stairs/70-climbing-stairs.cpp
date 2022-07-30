class Solution {
public:
    int memo[46] = {0};
    
    int climbStairs(int n) {
        if(memo[n] == 0) {
            if(n == 0) memo[n] = 1;
            else if(n == 1) memo[n] = 1;
            else {
                memo[n] = climbStairs(n-1) + climbStairs(n-2);
            }
        }
        return memo[n];
    }
};