class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) {
            string aux = a;
            a = b;
            b = aux;
        }
        
        int i, j;
        char cin = '0';
        for(i = a.length()-1, j = b.length()-1; i >= 0 and j >= 0;i--,j--) {
            char xorAB = (a[i]-'0') ^ (b[j]-'0');
            char andAB = (a[i]-'0') & (b[j]-'0');
            
            a[i] = (xorAB ^ (cin-'0')) + '0';
            cin = ((xorAB & (cin-'0')) | andAB) + '0';
        }
        
        while(i >= 0 and cin == '1') {
            char xorACin = (a[i]-'0') ^ (cin-'0');
            char andACin = (a[i]-'0') & (cin-'0');
            a[i] = xorACin + '0';
            cin = andACin + '0';
            i--;
        }
        
        if(cin == '1') {
            return '1' + a;
        }
        
        return a;
    }
};