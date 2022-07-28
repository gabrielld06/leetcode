#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) {
            x = 1/x;
            n *= -1;
        }
        double r;
        if(n & 1 == 1) {
            r = myPow(x, (n-1)/2);
            return x * r * r;
        } else {
            r = myPow(x, n/2);
            return r * r;
        }
    }
};

// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

int main() {

    cout << Solution().myPow(2, 10) << endl;
    cout << Solution().myPow(2.1, 3) << endl;
    cout << Solution().myPow(2, -2) << endl;

    return 0;
}