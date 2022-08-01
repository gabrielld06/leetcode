class Solution {
public:
    long memo[10001];
    
//     long dp(int n, vector<int> nums) {
//         if(n >= nums.size()) return 0;
//         if(memo[n] == -1) {
//             if(n == nums.size()-1) memo[n] = 0;
//             else {
//                 long m = 2147483647;
//                 for(int i = 1;i <= nums[n];i++) {
//                     m = min(m, 1 + dp(n+i, nums));
//                 }
//                 memo[n] = m;
//             }
//         }
//         return memo[n];
//     }
    
    long dp(int n, vector<int> nums) {
        memo[n-1] = 0;
        for(int i = n-2;i >= 0;i--) {
            long m = 2147483647;
            for(int j = 1;j <= nums[i];j++) {
                if(i+j < n) m = min(m, 1 + memo[i+j]);
                else m = min(m, (long) 1);
            }
            memo[i] = m;
        }
        return memo[0];
    }
    
    int jump(vector<int>& nums) {        
        return dp(nums.size(), nums);
    }
};