class Solution {
public:
    int bin_search(vector<int>& nums, int b, int e) {
        if(b > e) return -1;
        if(b == e) {
            if(b == 0 and nums[b] > nums[b + 1]) return b;
            if(b == 0) return -1;
            if(b == nums.size()-1 and nums[b-1] < nums[b]) return b;
            if(b == nums.size()-1) return -1;
            return -1;
        }
        
        int mid = b + (e - b) / 2;
        
        bool l = true, r = true;
        
        if(mid != 0) l = nums[mid-1] < nums[mid];
        if(mid != nums.size()-1) r = nums[mid] > nums[mid + 1];
        
        if (l and r) {
            return mid;
        } else {
            int left = bin_search(nums, b, mid);
            if(left != -1) return left;
            
            return bin_search(nums, mid+1, e);
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        return bin_search(nums, 0, nums.size() - 1);
    } 
};