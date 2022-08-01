class Solution {
public:
    int memo[101][101];
    
    int dp(int m, int n) {
        if(memo[m][n] == 0) {
            if(m == 0 and n == 0) memo[m][n] = 1;
            else if(m == 0) memo[m][n] = dp(m, n-1);
            else if(n == 0) memo[m][n] = dp(m-1, n);
            else memo[m][n] = dp(m-1, n) + dp(m, n-1);
        }
        return memo[m][n];
    }
    
    int uniquePaths(int m, int n) {
        return dp(m-1, n-1);
    }
};