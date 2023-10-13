class Solution {
public:
    int memo[1001];

    int solve(vector<int>& cost, int step) {
        if(memo[step] == -1) {
            memo[step] = min(solve(cost, step-1), solve(cost, step-2)) + cost[step];
        }

        return memo[step];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(memo, -1, sizeof(memo));

        memo[0] = cost[0];
        memo[1] = cost[1];

        return min(solve(cost, cost.size()-1), solve(cost, cost.size()-2));
    }
};