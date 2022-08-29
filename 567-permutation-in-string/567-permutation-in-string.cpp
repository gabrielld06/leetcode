class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for(int i = 0;i < s1.length();i++) {
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }
        
        int count = 0;
        for(int i = 0;i < 26;i++) {
            if(mp1[i] == mp2[i]) count++;
        }
        
        for(int i = 0;i + s1.length() < s2.length();i++) {
            if(count == 26) return true;
            
            int left = s2[i] - 'a', right = s2[i + s1.length()] - 'a';
            
            mp2[right]++;
            if(mp2[right] == mp1[right]) count++;
            else if(mp2[right] == mp1[right] + 1) count--;
            
            mp2[left]--;
            if(mp2[left] == mp1[left]) count++;
            else if(mp2[left] == mp1[left] - 1) count--;
        }
        return count == 26;
    }
};