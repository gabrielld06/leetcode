class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> mp;
        
        for(auto n : nums) {
            if(mp[n]) return true;
            mp[n] = true;
        }
        
        return false;
    }
};