class Solution {
public:
    int bin_search(vector<int>& nums, int target, int i, int j) {
        if(i >= j and nums[i] != target) {
            return -1;
        } else if(i >= j and nums[i] == target) {
            return i;            
        }
        
        int mid = i + (j - i) / 2;
        
        if(target > nums[mid]) return bin_search(nums, target, mid+1, j);
        if(target < nums[mid]) return bin_search(nums, target, i, mid);
        
        return mid;
    }
    
    int search(vector<int>& nums, int target) {
        return bin_search(nums, target, 0, nums.size()-1);
    }
};