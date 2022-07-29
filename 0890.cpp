class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        map<char, bool> r;
        
        for(int i = 0; i < s.length();i++) {
            if(mp[s[i]]) {
                if(mp[s[i]] != t[i]) {
                    return false;
                }
            } else if(not r[t[i]]) {
                mp[s[i]] = t[i];
                r[t[i]] = true;
            } else {
                return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto s : words) {
            if(isIsomorphic(s, pattern)) {
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};