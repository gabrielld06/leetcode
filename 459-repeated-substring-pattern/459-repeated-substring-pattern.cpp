class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool flag;
        for(int i = 1;i <= s.length()/2;i++) {
            flag = true;
            for(int j = i;j < s.length();j+=i) {
                // cout << s.substr(0, i) << " " << s.substr(j, i) << endl;
                if(s.substr(0, i) != s.substr(j, i)) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};