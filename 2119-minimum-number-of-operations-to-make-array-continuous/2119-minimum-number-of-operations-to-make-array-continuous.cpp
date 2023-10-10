class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> seen;
        vector<int> vet;

        for(auto e : nums) {
            if(seen.find(e) != seen.end()) continue;
            seen.insert(e);
        }

        for(auto e : seen) {
            vet.push_back(e);
        }

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