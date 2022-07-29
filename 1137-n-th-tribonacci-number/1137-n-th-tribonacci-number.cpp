class Solution {
public:
    int memo[38];
    
    int tribo(int n) {
        if(memo[n] == -1) {
            memo[n] = tribo(n-1) + tribo(n-2) + tribo(n-3);
        }
        return memo[n];
    }
    
    int tribonacci(int n) {
        memset(memo, -1, sizeof(memo));
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        tribo(n);
        
        return memo[n];
    }
};