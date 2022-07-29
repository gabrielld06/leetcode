class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        
        for(auto c : magazine) {
            count[c-'a']++;
        }
        
        for(auto c : ransomNote) {
            if(count[c-'a'] == 0) {
                return false;
            }
            count[c-'a']--;
        }
        
        return true;
    }
};