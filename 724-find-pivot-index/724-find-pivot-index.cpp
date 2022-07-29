class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for(auto n : nums) {
            totalSum += n;
        }
        int sum = 0;
        for(int i = 0;i < nums.size();i++) {
            totalSum -= nums[i];
            if(totalSum == sum) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};