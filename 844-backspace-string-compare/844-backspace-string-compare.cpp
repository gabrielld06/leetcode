class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1, j = t.length()-1;
        int decI = 0, decJ = 0;
        while(i >= 0 and j >= 0) {
            while(i >= 0 and (s[i] == '#' or decI > 0)) {
                if(s[i] == '#') decI++;
                else decI--;
                i--;
            }
            
            while(j >= 0 and (t[j] == '#' or decJ > 0)) {
                if(t[j] == '#') decJ++;
                else decJ--;
                j--;
            }

            if(j < 0 or i < 0) break;
            
            if(s[i] != t[j]) return false;
            
            i--;j--;
        }        
        
        while(i >= 0 and (s[i] == '#' or decI > 0)) {
            if(s[i] == '#') decI++;
            else decI--;
            i--;
        }

        while(j >= 0 and (t[j] == '#' or decJ > 0)) {
            if(t[j] == '#') decJ++;
            else decJ--;
            j--;
        }
        
        return (i == j);
    }
};