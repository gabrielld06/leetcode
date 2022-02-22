#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin = 1, i = 1, m = 0;
		map<char, int> mp;
		for(auto c : s) {
			if(mp[c] and mp[c] >= begin) {
				m = max(m, i - begin);
				int b = mp[c];
				while(b <= begin and b < s.length()) {
					b = mp[s[b]];
				}
				begin = b;
			}
			i++;
			mp[c] = i;
		}
		m = max(m, i - begin);
		return m;
	}
};

int main() {	
	
	assert(Solution().lengthOfLongestSubstring(string("abcabcbb")) == 3);
	assert(Solution().lengthOfLongestSubstring(string("bbbbb")) == 1);
	assert(Solution().lengthOfLongestSubstring(string("pwwkew")) == 3);
	assert(Solution().lengthOfLongestSubstring(string("dvdf")) == 3);
	assert(Solution().lengthOfLongestSubstring(string("abbbba")) == 2);
	assert(Solution().lengthOfLongestSubstring(string("tmmzuxt")) == 5);
	
	return 0;
}

