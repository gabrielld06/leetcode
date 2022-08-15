class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0; i < s.length();i++) {
            if(s[i] == '#') {
                int j = i;
                while(j >= 0 and s[j] == '#') {
                    j--;
                }
                if(j >= 0) s[j] = '#';
            }
        }
        
        for(int i = 0; i < t.length();i++) {
            if(t[i] == '#') {
                int j = i;
                while(j >= 0 and t[j] == '#') {
                    j--;
                }
                if(j >= 0) t[j] = '#';
            }
        }
        
        int i = 0, j = 0;
        
        while(i < s.length() and j < t.length()) {
            while(i < s.length() and s[i] == '#') {
                i++;
            }
            while(j < t.length() and t[j] == '#') {
                j++;
            }
            
            if(i == s.length() or j == t.length()) break;
            if(s[i] != t[j]) return false;
            
            i++;j++;
        }
        
        while(i < s.length() and s[i] == '#') {
            i++;
        }
        while(j < t.length() and t[j] == '#') {
            j++;
        }
        
        return i == s.length() and j == t.length();
    }
};