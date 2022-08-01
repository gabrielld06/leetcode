class Solution {
public:
    int memo[10001];

    int jump(vector<int>& nums) {   
        int n = nums.size();
        memo[n-1] = 0;
        for(int i = n-2;i >= 0;i--) {
            int m = 10001;
            for(int j = 1;j <= nums[i];j++) {
                if(i+j < n) m = min(m, 1 + memo[i+j]);
                else m = min(m, 1);
            }
            memo[i] = m;
        }
        return memo[0];
    }
};