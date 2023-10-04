class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int seen[101] = {0};
        int pairs = 0;
        for(int i = 0;i < nums.size();i++) {
            pairs += seen[nums[i]];
            seen[nums[i]]++;
        }

        return pairs;
    }
};