class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        
        int i = 1;
        
        while(i < nums.size() and nums[i] == nums[i-1]) {
            i++;
        }
        
        if(i < nums.size() and nums[i] > nums[i-1]) {
            while(i < nums.size() and nums[i] >= nums[i-1]) {
                i++;
            }
        } else {
            while(i < nums.size() and nums[i] <= nums[i-1]) {
                i++;
            }
        }
        
        return i == nums.size();
    }
};