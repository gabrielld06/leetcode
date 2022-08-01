class Solution {
public:
    int max_v, min_v;
    map<int, int> count;
    int memo[20069];
    
    int dp(int n) {
        if(memo[n] == -1) {
            if(n > max_v) memo[n] = 0;
            else if(n == max_v) memo[n] = count[n]*n;
            else {
                memo[n] = max((count[n] * n) + dp(n+2), dp(n+1));
            }
        }
        return memo[n];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        
        max_v = nums[0];
        min_v = nums[0];
        
        for(auto n : nums) {
            count[n]++;
            max_v = max(max_v, n);
            min_v = min(min_v, n);
        }
        
        return dp(min_v);
    }
};