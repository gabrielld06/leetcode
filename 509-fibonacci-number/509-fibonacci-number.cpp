class Solution {
public:
    int memo[31];
    
    int fibo(int n) {
        if(memo[n] == -1) {
            memo[n] = fibo(n-1) + fibo(n-2);
        }
        return memo[n];
    }
    
    int fib(int n) {
        memset(memo, -1, sizeof(memo));
        
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        fibo(n);
        
        return memo[n];
     }
};