class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), max_atual = nums[0], max_total = nums[0], left_index = 0;
        
        max_atual = nums[0];
        for(int i = 1;i < n;i++) {
            max_atual = nums[i] + (max_atual > 0 ? max_atual : 0);
            
            max_total = max(max_atual, max_total);
        }
        
        int right_sum[n];
        right_sum[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;i--) {
            right_sum[i] = right_sum[i+1] + nums[i];
        }
        
        int max_right[n];
        max_right[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;i--) {
            max_right[i] = max(max_right[i+1], right_sum[i]);
        }
        
        int left_sum = 0;
        right_sum[n-1] = nums[n-1];
        for(int i = 0;i < n-2;i++) {
            left_sum += nums[i];
            
            max_total = max(left_sum + max_right[i+2], max_total);
        }
        
        return max_total;
    }
};