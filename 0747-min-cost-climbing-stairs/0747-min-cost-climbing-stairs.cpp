class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int memo[1001], n = cost.size();

        memo[0] = cost[0];
        memo[1] = cost[1];

        for(int i = 2;i < n;i++) {
            memo[i] = (memo[i - 1] < memo[i - 2] ? memo[i - 1] : memo[i - 2]) + cost[i];
        }

        return (memo[n - 1] < memo[n - 2] ? memo[n - 1] : memo[n - 2]);
    }
};