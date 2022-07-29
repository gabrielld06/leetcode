class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < t.length() and j < s.length()) {
            if(t[i] == s[j]) {
                j++;
            }
            i++;
        }
        
        if(j == s.length()) {
            return true;
        } else {
            return false;
        }
    }
};