class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mult_atual = 1, ans = nums[0];
        
        for(int i = 0;i < nums.size();i++) {
            mult_atual *= nums[i];
            ans = (mult_atual > ans ? mult_atual : ans);
            
            if(nums[i] == 0) {
                mult_atual = 1;
            }
        }
        
        mult_atual = 1;
        for(int i = nums.size()-1;i >= 0;i--) {
            mult_atual *= nums[i];
            ans = (mult_atual > ans ? mult_atual : ans);
            
            if(nums[i] == 0) {
                mult_atual = 1;
            }
        }
        
        return ans;
    }
};