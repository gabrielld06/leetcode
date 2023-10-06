class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int min_appearence = nums.size()/3 + 1;
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;

        for(int i = 0;i < nums.size();i++) {
             if(count1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                count1++;
            } else if(count2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                count2++;
            } else if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            }
        }

        vector<int> ans;

        if(count1 >= min_appearence) {
            ans.push_back(candidate1);
        }
        if(count2 >= min_appearence) {
            ans.push_back(candidate2);
        }

        return ans;
    }
};