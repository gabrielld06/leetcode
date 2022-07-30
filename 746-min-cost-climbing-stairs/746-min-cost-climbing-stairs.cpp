class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int memo[1001];
        int n = cost.size();
        
        memo[0] = cost[0];
        memo[1] = cost[1];
        
        for(int i = 2;i < n;i++) {
            memo[i] = cost[i] + min(memo[i-1], memo[i-2]);
        }
        
        memo[n] = min(memo[n-1], memo[n-2]);
        
        return memo[n];
    }
};