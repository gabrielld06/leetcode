class Solution {
public:
    int longestPalindrome(string s) {
        int countLower[26] = {0};
        int countUpper[26] = {0};
        
        for(char c : s) {
            if('a' <= c and c <= 'z') {
                countLower[c-'a']++;
            } else {
                countUpper[c-'A']++;
            }
        }
        
        int l = 0, flag = 0;
        
        for(int i = 0;i < 26;i++) {
            if(countLower[i] % 2 == 0) {
                l += countLower[i];
            } else {
                l += countLower[i]-1;
                flag = 1;
            }
            if(countUpper[i] % 2 == 0) {
                l += countUpper[i];
            } else {
                l += countUpper[i]-1;
                flag = 1;
            }
        }
        
        return l + flag;
    }
};