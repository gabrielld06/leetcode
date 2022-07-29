class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sig = 1;
        long val = 0, digit = 1;
        string r = "";
        
        while(s[i] == ' ') {
            i++;
        }
        
        if(s[i] == '-') {
            sig = -1;
            i++;
        } else if(s[i] == '+') {
            sig = 1;
            i++;
        }
        
        while(s[i] == '0') {
            i++;
        }
        
        while('0' <= s[i]  and s[i] <= '9') {
            r += s[i];
            i++;
        }
        
        for(int j = r.length()-1;j >= 0;j--){
            val += (r[j] - '0') * digit;
            digit *= 10;
            if(val > 2147483648 or digit > 10000000000){
                val = 2147483649;
                break;
            }
        }
        
        val *= sig;
        
        if(val > 2147483647){
            val = 2147483647;
        }
        if(val < -2147483648){
            val = -2147483648;
        }
        
        return val;
    }
};