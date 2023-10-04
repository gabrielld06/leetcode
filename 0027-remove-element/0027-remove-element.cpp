class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0, count = 0;
        while(i < nums.size() && j < nums.size()) {
            while(i < nums.size() && nums[i] != val) i++;
            j = i;
            while(j < nums.size() && nums[j] == val) j++;
            if(i < nums.size() && j < nums.size() && nums[i] == val) swap(nums[i], nums[j]);
        }
        return i;
    }
};