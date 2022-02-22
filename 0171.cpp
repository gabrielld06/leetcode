#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		int ans = 0, exp = 0;
        for(int i = s.size()-1;i >= 0;i--) {
			ans += pow(26, exp) * (s[i]-64);
            exp++;
		}
		return ans;
    }
};

int main() {
	
	assert(Solution().titleToNumber(string("A")) == 1);
	assert(Solution().titleToNumber(string("AB")) == 28);
	assert(Solution().titleToNumber(string("ZY")) == 701);
	
	return 0;
}
