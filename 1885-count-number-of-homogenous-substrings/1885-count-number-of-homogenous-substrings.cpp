class Solution {
public:
    int countHomogenous(string s) {
        const long magic_number = 1000000007; 
        char at = s[0];
        long count = 1;
        long total = 0;
        for(int i = 1; i < s.length();i++) {
            if(s[i] != at) {
                total = (total + ((count + count * count) >> 1)) % magic_number;

                at = s[i];
                count = 1;
            } else {
                count++;
            }
        }

        total = (total + ((count + count * count) >> 1)) % magic_number;

        return total % magic_number;
    }
};

/*
zzzzz
#5 = 1
#4 = 2
#3 = 3
#2 = 4
#1 = 5

bb
#2 = 1
#1 = 2

ccc
#3 = 1
#2 = 2
#1 = 3

S = ((a1 + an) * n) / 2
*/