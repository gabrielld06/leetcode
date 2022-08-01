class Solution {
public:
    int memo[101];
    
    int dp(int n, vector<int> nums){
        if(memo[n] == -1) {
            if(n == 0) memo[n] = nums[0];
            else if(n == 1) memo[n] = max(nums[n], dp(n-1, nums));
            else {
                memo[n] = max(nums[n] + dp(n-2, nums), dp(n-1, nums));
            }
        }
        return memo[n];
    }
    
    int rob(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return dp(nums.size()-1, nums);
    }
};