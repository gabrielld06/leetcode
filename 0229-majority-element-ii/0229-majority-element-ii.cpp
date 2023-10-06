class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int min_appearence = nums.size()/3 + 1;
        vector<int> ans;
        map<int, int> appearence;
        for(int i = 0;i < nums.size();i++) {
            appearence[nums[i]]++;
            if(appearence[nums[i]] == min_appearence) ans.push_back(nums[i]); 
        }

        return ans;
    }
};