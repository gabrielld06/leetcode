class Solution {
public:    
    int maxSubArray(vector<int>& nums) {
        int memo[100001] = {0};
        int m = nums[0];
        memo[0] = nums[0];
        
        for(int i = 1;i < nums.size();i++) {
            memo[i] = nums[i] + (memo[i-1] > 0 ? memo[i-1] : 0);
            m = max(memo[i], m);
        }
        
        return m;
    }
};