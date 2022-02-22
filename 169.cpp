#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
		for(auto c : nums) {
			mp[c]++;
			if(mp[c] > nums.size()/2) return c;
		}
		return 0;
    }
};

int main() {	
	vector<int> a = { 3,2,3 };
	vector<int> b = { 2,2,1,1,1,2,2 };
	
	assert(Solution().majorityElement(a) == 3);
	assert(Solution().majorityElement(b) == 2);
	
	return 0;
}