class Solution {
public:
    bool canJump(vector<int>& nums) {
        int d = 1;
        for(int i = 0;i < nums.size();i++) {
            if(d == 0) return false;
            d = (d-1  > nums[i] ? d-1 : nums[i]);
        }
        
        return true;
    }
};