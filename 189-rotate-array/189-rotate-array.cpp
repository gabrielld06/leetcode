class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int m = nums.size() - k % nums.size();
        for(int i = m;i < nums.size();i++) {
            ans.push_back(nums[i]);
        }
        
        for(int i = 0;i < m;i++) {
            ans.push_back(nums[i]);
        }
        
        nums = ans;
    }
};