class Solution {
public:
    int romanToInt(string s) {
        int i = 0, ans = 0;
        while(i < s.length()) {
            if(s[i] == 'I') {
                if(i < s.length()-1 and s[i+1] == 'V') {
                    ans += 4;
                    i++;
                } else if(i < s.length()-1 and s[i+1] == 'X') {
                    ans += 9;
                    i++;
                } else {                    
                    ans += 1;
                }
            } else if(s[i] == 'X') {
                if(i < s.length()-1 and s[i+1] == 'L') {
                    ans += 40;
                    i++;
                } else if(i < s.length()-1 and s[i+1] == 'C') {
                    ans += 90;
                    i++;
                } else {                    
                    ans += 10;
                }
            } else if(s[i] == 'C') {
                if(i < s.length()-1 and s[i+1] == 'D') {
                    ans += 400;
                    i++;
                } else if(i < s.length()-1 and s[i+1] == 'M') {
                    ans += 900;
                    i++;
                } else {
                    ans += 100;
                }
            } else if(s[i] == 'V'){ 
                    ans += 5;
            } else if(s[i] == 'L'){ 
                    ans += 50;
            } else if(s[i] == 'D'){ 
                    ans += 500;
            } else if(s[i] == 'M'){ 
                    ans += 1000;
            }
            i++;
        }
        return ans;
    }
};