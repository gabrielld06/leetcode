class Solution {
public:
    bool canJump(vector<int>& nums) {
        int memo[10001] = {0};
        memo[0] = true;
        int d = 1;
        for(int i = 0;d > 0 and i < nums.size();i++) {
            d--;
            memo[i] = true;
            d = max(d, nums[i]);
        }
        
        return memo[nums.size()-1];
    }
};