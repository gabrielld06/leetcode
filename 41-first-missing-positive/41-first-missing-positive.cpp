class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // for(auto no : nums) cout << no << " ";
        // cout << endl;
        int aux;
        for(int i = 0; i < nums.size();i++) {
            while(nums[i] > 0 and nums[i] <= nums.size() and nums[i] != nums[nums[i]-1]) {
                aux = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[aux-1] = aux;
            }
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