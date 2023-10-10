class Solution {
public:
    int bin_search(vector<int>& nums, int i, int j, int target) {
        if(i > j) return i;

        int mid = i + (j - i) / 2;

        if(nums[mid] == target) {
            return mid + 1;
        }

        if(nums[mid] < target) {
            return bin_search(nums, mid+1, j, target);
        } else {
            return bin_search(nums, i, mid-1, target);
        }
    }

    int minOperations(vector<int>& nums) {
        set<int> seen;
        vector<int> vet;
        for(auto e : nums) {
            if(seen.find(e) != seen.end()) continue;
            seen.insert(e);
            vet.push_back(e);
        }
        sort(vet.begin(), vet.end());
        int min_operations = nums.size();
        for(int i = 0; i < vet.size();i++) {
            int target =  vet[i] + nums.size() - 1;
            int index = upper_bound(vet.begin(), vet.end(), target) - vet.begin();
            int operations = i + nums.size() - index;
            min_operations = min(min_operations, operations);
        }

        return min_operations;
    }
};