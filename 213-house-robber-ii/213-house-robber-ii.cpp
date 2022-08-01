class Solution {
public:
    int memo[101][2];
    
    int dp(vector<int>& nums, int n, int f) {
        if(n == -1) return 0;
        if(memo[n][f] == -1) {
            memo[n][f] = max(nums[n] + dp(nums, n-2, f), dp(nums, n-1, f));
        }
        return memo[n][f];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        memset(memo, -1, sizeof(memo));
        memo[0][1] = 0;
        memo[0][0] = nums[0];
        return max(nums[nums.size()-1] + dp(nums, nums.size()-3, 1), dp(nums, nums.size()-2, 0));
    }
};