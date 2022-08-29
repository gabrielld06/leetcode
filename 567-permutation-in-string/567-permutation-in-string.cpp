class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26, 0);
        for(auto c : s1) {
            mp1[c - 'a']++;
        }
        vector<int> mp2(26, 0);
        for(auto c : s2) {
            mp2[c - 'a']++;
        }
        
        bool f = false;
        
        for(int i = 0;i + s1.length() <= s2.length();i++) {
            if(mp1[s2[i] - 'a'] > 0) {
                vector<int> mp3(26, 0);
                f = false;
                for(int j = 0;j < s1.length();j++) {
                    mp3[s2[i + j] - 'a']++;
                    if(mp1[s2[i + j]  - 'a'] < mp3[s2[i + j] - 'a']) {
                        f = true;
                        break;
                    }
                }
                if(not f) return true;
            }
            
            mp2[s2[i]  - 'a']--;
            if(mp2[s2[i]  - 'a'] < mp1[s2[i]  - 'a']) return false;
        }
        return false;
    }
};