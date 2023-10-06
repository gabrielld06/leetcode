class Solution {
public:
    vector<int> dp = vector<int>(59, 0);

    int solve(int n, int o) {
        if(dp[n] == 0) {
            if(n == 0) {
                dp[n] = 1;
            } else if(n == 1) {
                dp[n] = 1;
            } else {
                int ans = -1;
                for(int i = 1;i < n;i++) {
                    ans = max(ans, (n-i) * solve(i, o));
                }
                if(n != o) {
                    dp[n] = max(ans, n);
                } else {
                    dp[n] = ans;
                }
            }
        }

        return dp[n];
    }

    int integerBreak(int n) {
        return solve(n, n);
    }
};