class Solution {
public:
    int power(long int n, long int exp) {
        if(exp == 0) return 1;
        if(exp & 1 == 1) {
            long int r = power(n, (exp - 1)/2) % 1337;
            return (n * r * r) % 1337;
        } else {
            int r = power(n, exp/2) % 1337;
            return (r * r) % 1337;
        }
    }
    
    int superPow(int a, vector<int>& b) {
        int ans = 1, p, n = b.size()-1, digit = 1;
        a = a % 1337;
        for(int i = 0;i < b.size();i++) {
            p = power(a, (b[n-i] * digit) % 1140) % 1337;
            ans = (ans * p)  % 1337;
            digit = (digit * 10) % 1140;
        }
         
        return ans;
    }
};