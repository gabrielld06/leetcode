class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mult_atual = 1, ans = nums[0], left_mul = 1;
        
        for(int i = 0;i < nums.size();i++) {
            mult_atual *= nums[i];
            left_mul *= nums[i];
            ans = max(mult_atual, max(left_mul, ans));
            if(nums[i] < 0) {
                mult_atual = 1;
            } else if(nums[i] == 0) {
                left_mul = 1;
                mult_atual = 1;
            }
        }
        
        mult_atual = 1, left_mul = 1;
        for(int i = nums.size()-1;i >= 0;i--) {
            mult_atual *= nums[i];
            left_mul *= nums[i];
            ans = max(mult_atual, max(left_mul, ans));
            if(nums[i] < 0) {
                mult_atual = 1;
            } else if(nums[i] == 0) {
                left_mul = 1;
                mult_atual = 1;
            }
        }
        
        return ans;
    }
};