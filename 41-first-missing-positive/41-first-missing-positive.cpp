class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // for(auto no : nums) cout << no << " ";
        // cout << endl;
        int n = 0;
        for(int i = 0; i < nums.size();i++) {
            int j = i;
            if(nums[j] > 0 and nums[j] <= nums.size() and nums[j] != nums[nums[j]-1]) {
                while(nums[j] > 0 and nums[j] <= nums.size() and nums[j] != nums[nums[j]-1]) {
                    int aux = nums[j];
                    nums[j] = nums[nums[j]-1];
                    nums[aux-1] = aux;
                    n++;
                }
            } else n++;
        }
        
        // for(auto no : nums) cout << no << " ";
        // cout << endl;
        
        for(int i = 0; i < nums.size();i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        
        return nums.size()+1;
    }
};