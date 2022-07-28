#include <bits/stdc++.h>

using namespace std;

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
};

int main() {
	return 0;
}