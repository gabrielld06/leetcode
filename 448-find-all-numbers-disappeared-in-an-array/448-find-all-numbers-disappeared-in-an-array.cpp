class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int count[100001] = {0};
        for(auto n : nums) {
            count[n]++;
        }
        vector<int> ans;
        for(int i = 1;i <= nums.size();i++) {
            if(count[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};